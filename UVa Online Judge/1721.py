x_max = None
y_max = None
n_command = None
windows = []

class Window:
    def __init__(self, x, y, w, h):
        self.x = x
        self.y = y
        self.w = w
        self.h = h

    def isOverlapWith(self, window):
        leftmost = min(self.x, window.x)
        rightmost = max(self.x + self.w, window.x + window.w)
        topmost = min(self.y, window.y)
        bottommost = max(self.y + self.h, window.y + window.h)

        sum_width = self.w + window.w
        sum_height = self.h + window.h
        if rightmost - leftmost < sum_width and bottommost - topmost < sum_height:
            return True
        return False

    def isInside(self, x, y):
        if self.x <= x < self.x + self.w and \
           self.y <= y < self.y + self.h: return True
        return False

    def isOutOfBound(self, x_max, y_max):
        if self.x < 0 or self.y < 0: return True
        if self.x + self.w > x_max: return True
        if self.y + self.h > y_max: return True
        return False

    def __repr__(self):
        return "(x={},y={},w={},h={})".format(self.x, self.y, self.w, self.h)

def processInit(line):
    global x_max, y_max, n_command, windows

    if x_max is not None: processDone()
    x_max, y_max = list(map(int, line.split()))
    n_command = 0
    windows = []

def move(window_idx, axis, dist, direction):
    global x_max, y_max, n_command, windows
    curr_windows = [window_idx]

    target_dist = dist # -dy
    actual_dist = 0
    while dist > 0:
        min_window = -1
        min_dist = 4e9
        for i in range(len(windows)):
            if i in curr_windows: continue
            for k in curr_windows:
                if axis == 'y' and max(windows[i].x + windows[i].w, windows[k].x + windows[k].w) - \
                                   min(windows[i].x, windows[k].x) < windows[i].w + windows[k].w:
                    if direction > 0: d = windows[i].y - (windows[k].y + windows[k].h)
                    else:             d = windows[k].y - (windows[i].y + windows[i].h)
                    if d < 0: continue
                    if d < min_dist:
                        min_dist = d
                        min_window = i
                elif axis == 'x' and max(windows[i].y + windows[i].h, windows[k].y + windows[k].h) - \
                                     min(windows[i].y, windows[k].y) < windows[i].h + windows[k].h:
                    if direction > 0: d = windows[i].x - (windows[k].x + windows[k].w)
                    else:             d = windows[k].x - (windows[i].x + windows[i].w)
                    if d < 0:  continue
                    if d < min_dist:
                        min_dist = d
                        min_window = i


        movement = min(dist, min_dist)
        print("movement = {}".format(movement))
        out_of_bound = False
        for k in curr_windows:
            if axis == 'y' and direction < 0 and windows[k].y - movement < 0:
                out_of_bound = True
                movement = min(movement, windows[k].y)
            elif axis == 'y' and direction > 0 and windows[k].y + windows[k].h + movement > y_max:
                out_of_bound = True
                movement = min(movement, y_max - windows[k].y  - windows[k].h)
            elif axis == 'x' and direction < 0 and windows[k].x - movement < 0:
                out_of_bound = True
                movement = min(movement, windows[k].x)
            elif axis == 'x' and direction > 0 and windows[k].x + windows[k].w + movement > x_max:
                out_of_bound = True
                movement = min(movement, x_max - windows[k].x  - windows[k].w)
        for k in curr_windows:
            if axis == 'y': windows[k].y = windows[k].y + direction * movement
            else:           windows[k].x = windows[k].x + direction * movement
            
        actual_dist += movement
        dist -= movement
        if min_window != -1: curr_windows.append(min_window)
        # print("{} move {} {}".format(out_of_bound, movement, curr_windows), windows)
        if out_of_bound: break

    
    if actual_dist < target_dist:
        print("Command {}: MOVE - moved {} instead of {}".format(n_command, actual_dist, target_dist))

def processCommand(line):
    global x_max, y_max, n_command, windows

    line = line.split()
    command = line[0]
    params = list(map(int, line[1:]))

    n_command += 1
    if command == "OPEN":
        x, y, w, h = params
        new_window = Window(x, y, w, h)

        if new_window.isOutOfBound(x_max, y_max):
            print("Command {}: OPEN - window does not fit".format(n_command))
            return

        overlap = False
        for window in windows:
            if new_window.isOverlapWith(window):
                overlap = True
                break

        if overlap:
            print("Command {}: OPEN - window does not fit".format(n_command))
            return
        windows.append(new_window)
    elif command == "CLOSE":       
        x, y = params

        found = False
        for i, window in enumerate(windows):
            if window.isInside(x, y):
                found = True
                del windows[i]
                break
        
        if not found:
            print("Command {}: CLOSE - no window at given position".format(n_command))

    elif command == "RESIZE":
        x, y, w, h = params

        found = False
        window_idx = -1
        for i, window in enumerate(windows):
            if window.isInside(x, y):
                found = True
                window_idx = i
                break

        if not found:
            print("Command {}: RESIZE - no window at given position".format(n_command))
            return

        old_w = windows[window_idx].w
        old_h = windows[window_idx].h
        windows[window_idx].w = w
        windows[window_idx].h = h

        if windows[window_idx].isOutOfBound(x_max, y_max):
            windows[window_idx].w = old_w
            windows[window_idx].h = old_h
            print("Command {}: RESIZE - window does not fit".format(n_command))
            return

        overlap = False
        for i in range(len(windows)):
            if i == window_idx: continue
            if windows[window_idx].isOverlapWith(windows[i]):
                overlap = True
                break

        if overlap:
            windows[window_idx].w = old_w
            windows[window_idx].h = old_h
            print("Command {}: RESIZE - window does not fit".format(n_command))
            return
    elif command == "MOVE":
        x, y, dx, dy = params

        found = False
        window_idx = -1
        for i, window in enumerate(windows):
            if window.isInside(x, y):
                found = True
                window_idx = i
                break

        if not found:
            print("Command {}: MOVE - no window at given position".format(n_command))
            return

        if dx > 0:    move(window_idx, 'x', dx, 1)
        elif dx < 0:  move(window_idx, 'x', -dx, -1)
        elif dy > 0:  move(window_idx, 'y', dy, 1)
        else:         move(window_idx, 'y', -dy, -1)

def processDone():
    global x_max, y_max, n_command, windows

    print("{} window(s):".format(len(windows)))
    for window in windows:
        print("{} {} {} {}".format(window.x, window.y, window.w, window.h))

while True:
    try: 
        line = input()
    except EOFError:
        break

    if len(line.split()) == 2: processInit(line)
    else: processCommand(line)

processDone()