#include <bits/stdc++.h>
using namespace std;

long long x_max, y_max;
int n_command;
class Rectangle {
    public:
    long long x, y, w, h;

    Rectangle(){}
    Rectangle(long long x, long long y, long long w, long long h): x(x), y(y), w(w), h(h) {}

    bool isOutOfBound(long long x_max, long long y_max){
        if(x < 0 or y < 0) return true;
        if(x + w > x_max) return true;
        if(y + h > y_max) return true;
        return false;
    }

    bool isInside(long long xx, long long yy){
        if(x <= xx and xx < x + w and y <= yy and yy < y + h) return true;
        return false;
    }

    bool isOverlapWith(Rectangle window){
        long long leftmost = min(x, window.x);
        long long rightmost = max(x + w, window.x + window.w);
        long long topmost = min(y, window.y);
        long long bottommost = max(y + h, window.y + window.h);

        long long sum_width = w + window.w;
        long long sum_height = h + window.h;
        if(rightmost - leftmost < sum_width and bottommost - topmost < sum_height) return true;
        return false;
    }
};

vector <Rectangle> windows;

void move(int window_idx, char axis, long long dist, int direction){
    vector <int> curr_windows;
    curr_windows.push_back(window_idx);

    long long target_dist = dist;
    long long actual_dist = 0;
    while(dist > 0){
        int min_window = -1;
        long long min_dist = 1e18, d;

        for(int i=0; i<windows.size(); i++){
            bool skip_i = false;
            for(int k=0; k<curr_windows.size(); k++){
                if(curr_windows[k] == i){
                    skip_i = true;
                    break;
                }
            }
            if(skip_i) continue;

            for(int kk=0; kk<curr_windows.size(); kk++){
                int k = curr_windows[kk];
                if(axis == 'y' and max(windows[i].x + windows[i].w, windows[k].x + windows[k].w) - \
                       min(windows[i].x, windows[k].x) < windows[i].w + windows[k].w){
                    if(direction > 0) d = windows[i].y  - (windows[k].y + windows[k].h);
                    else              d = windows[k].y - (windows[i].y + windows[i].h);
                    if(d < 0) continue;
                    if(d < min_dist){
                        min_dist = d;
                        min_window = i;
                    }
                }else if(axis == 'x' and max(windows[i].y + windows[i].h, windows[k].y + windows[k].h) - \
                                         min(windows[i].y, windows[k].y) < windows[i].h + windows[k].h){
                    if(direction > 0) d = windows[i].x - (windows[k].x + windows[k].w);
                    else              d = windows[k].x - (windows[i].x + windows[i].w);
                    if(d < 0) continue;
                    if(d < min_dist){
                        min_dist = d;
                        min_window = i;
                    }
                }         
            }
        }

        long long movement = min(dist, min_dist);
        bool out_of_bound = false;
        for(int kk=0; kk<curr_windows.size(); kk++){
            int k = curr_windows[kk];
            if(axis == 'y' and direction < 0 and windows[k].y - movement < 0){
                out_of_bound = true;
                movement = min(movement, windows[k].y);
            }else if(axis == 'y' and direction > 0 and windows[k].y + windows[k].h + movement > y_max){
                out_of_bound = true;
                movement = min(movement, y_max - windows[k].y - windows[k].h);
            }else if(axis == 'x' and direction < 0 and windows[k].x - movement < 0){
                out_of_bound = true;
                movement = min(movement, windows[k].x);
            }else if(axis == 'x' and direction > 0 and windows[k].x + windows[k].w + movement > x_max){
                out_of_bound = true;
                movement = min(movement, x_max - windows[k].x - windows[k].w);
            }
        }

        for(int kk=0; kk<curr_windows.size(); kk++){
            int k = curr_windows[kk];
            if(axis == 'y') windows[k].y = windows[k].y + direction * movement;
            else            windows[k].x = windows[k].x + direction * movement;
        }
        actual_dist += movement;
        dist -= movement;
        if(min_window != -1) curr_windows.push_back(min_window);
        if(out_of_bound) break;
    }
    if(actual_dist < target_dist) printf("Command %d: MOVE - moved %lld instead of %lld\n", n_command, actual_dist, target_dist);
}

int main(){
    char tmp_cstr[100];
    string command;
    
    while(scanf("%s", tmp_cstr) == 1){
        if(tmp_cstr[0] >= '0' and tmp_cstr[0] <= '9'){
            if(x_max > 0){
                printf("%d window(s):\n", windows.size());
                for(int i=0; i<windows.size(); i++){
                    printf("%lld %lld %lld %lld\n", windows[i].x, windows[i].y, windows[i].w, windows[i].h);
                }
            }
            x_max = atol(tmp_cstr);
            scanf("%lld", &y_max);
            n_command = 0;
            windows.clear();
            continue;
        }
        
        command = tmp_cstr;
        n_command++;
        if(command == "OPEN"){
            long long x, y, w, h;
            scanf("%lld %lld %lld %lld", &x, &y, &w, &h);
            Rectangle new_window(x, y, w, h);
            if(new_window.isOutOfBound(x_max, y_max)){
                printf("Command %d: OPEN - window does not fit\n", n_command);
                continue;
            }
            bool overlap = false;
            for(int i=0; i<windows.size(); i++){
                if(new_window.isOverlapWith(windows[i])){
                    overlap = true;
                    break;
                }
            }
            if(overlap){
                printf("Command %d: OPEN - window does not fit\n", n_command);
                continue;
            }
            windows.push_back(new_window);
        }else if(command == "CLOSE"){
            long long x,y;
            scanf("%lld %lld", &x, &y);

            bool found = false;
            int found_idx = -1;
            for(int i=0; i<windows.size(); i++){
                if(windows[i].isInside(x, y)){
                    found = true;
                    found_idx = i;
                    break;
                }
            }
            
            if(not found) printf("Command %d: CLOSE - no window at given position\n", n_command);
            else windows.erase(windows.begin() + found_idx);
        }else if(command == "RESIZE"){
            long long x, y, w, h;
            scanf("%lld %lld %lld %lld", &x, &y, &w, &h);

            bool found = false;
            int window_idx = -1;
            for(int i=0; i<windows.size(); i++){
                if(windows[i].isInside(x, y)){
                    found = true;
                    window_idx = i;
                    break;
                }
            }
            if(not found){
                printf("Command %d: RESIZE - no window at given position\n", n_command);
                continue;
            }

            long long old_w = windows[window_idx].w;
            long long old_h = windows[window_idx].h;
            windows[window_idx].w = w;
            windows[window_idx].h = h;

            if(windows[window_idx].isOutOfBound(x_max, y_max)){
                windows[window_idx].w = old_w;
                windows[window_idx].h = old_h;
                printf("Command %d: RESIZE - window does not fit\n", n_command);
                continue;
            }

            bool overlap = false;
            for(int i=0; i<windows.size(); i++){
                if(i == window_idx) continue;
                if(windows[window_idx].isOverlapWith(windows[i])){
                    overlap = true;
                    break;
                }
            }
            if(overlap){
                windows[window_idx].w = old_w;
                windows[window_idx].h = old_h;
                printf("Command %d: RESIZE - window does not fit\n", n_command);
                continue;
            }
        }else if(command == "MOVE"){
            long long x, y, dx, dy;
            scanf("%lld %lld %lld %lld", &x, &y, &dx, &dy);

            bool found = false;
            int window_idx = -1;
            for(int i=0; i<windows.size(); i++){
                if(windows[i].isInside(x, y)){
                    found = true;
                    window_idx = i;
                    break;
                }
            }

            if(not found){
                printf("Command %d: MOVE - no window at given position\n", n_command);
                continue;
            }

            if(dx > 0)      move(window_idx, 'x', dx, 1);
            else if(dx < 0) move(window_idx, 'x', -dx, -1);
            else if(dy > 0) move(window_idx, 'y', dy, 1);
            else            move(window_idx, 'y', -dy, -1);
        }
    }

    printf("%d window(s):\n", windows.size());
    for(int i=0; i<windows.size(); i++){
        printf("%lld %lld %lld %lld\n", windows[i].x, windows[i].y, windows[i].w, windows[i].h);
    }

    return 0;
}