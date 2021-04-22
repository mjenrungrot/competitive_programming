# =============================================================================
#  Author:          Teerapat Jenrungrot - https://github.com/mjenrungrot/
#  FileName:        592.py
#  Description:     UVa Online Judge - 592
# =============================================================================

def parse(line):
    speaker, content = line.strip().split(': ')
    content = content.replace('.', '')
    content_tokens = content.split()
    return speaker, content_tokens


def decode_assignments(num):

    def num_to_word(x):
        if x == 0:
            return 'divine'
        elif x == 1:
            return 'human'
        else:
            return 'evil'

    assignments = {}
    assignments['A'] = num_to_word(num % 3)
    assignments['B'] = num_to_word((num % 9) // 3)
    assignments['C'] = num_to_word((num % 27) // 9)
    assignments['D'] = num_to_word((num % 81) // 27)
    assignments['E'] = num_to_word((num % 243) // 81)
    assignments['It'] = 'day' if num < 243 else 'night'
    return assignments


def is_lying(speaker, assignment, target_value, target_self, target_negative,
             is_day):

    if assignment in ["day", "night"]:
        if speaker == "divine" or (speaker == "human" and is_day):
            if is_day and target_value == "night":
                return True
            elif (not is_day) and target_value == "day":
                return True
            else:
                return False
        else:
            if is_day and target_value != "night":
                return True
            elif (not is_day) and target_value != "day":
                return True
            else:
                return False

    # I am not (divine/human/evil/lying).
    if target_negative and target_self:
        if speaker == "divine":
            if target_value == "divine":
                return True  # I am not divine.
            else:
                return False
        elif speaker == "evil":
            if target_value == "evil" or target_value == "lying":
                return False
            else:
                return True  # I am not (evil/lying).
        else:
            if is_day:
                if target_value == "human":
                    return True  # I am not human.
                else:
                    return False
            else:
                if target_value == "human" or target_value == "lying":
                    return False
                else:
                    return True  # I am not (divine/evil).
    # X is not (divine/human/evil/lying).
    elif target_negative:
        if speaker == "divine" or (speaker == "human" and is_day):
            if assignment == "divine" and target_value == "divine":
                return True  # X is not divine.
            elif assignment == "evil" and target_value == "evil":
                return True  # X is not evil.
            elif assignment == "human" and target_value == "human":
                return True  # X is not human.
            elif target_value == "lying":  # X is not lying.
                if assignment == "divine" or (assignment == "human" and is_day):
                    return False
                else:
                    return True
            else:
                return False
        else:
            if assignment == "divine" and (target_value == "evil" or
                                           target_value == "human"):
                return True  # X is not (evil/human).
            elif assignment == "evil" and (target_value == "divine" or
                                           target_value == "human"):
                return True  # X is not (divine/human).
            elif assignment == "human" and (target_value == "divine" or
                                            target_value == "evil"):
                return True  # X is not (divine/evil).
            elif target_value == "lying":
                if assignment == "evil" or (assignment == "human" and
                                            not is_day):
                    return False
                else:
                    return True  # X is not lying.
            else:
                return False
    elif target_self:
        if speaker == "divine":
            if target_value == "divine":
                return False  # I am divine.
            else:
                return True
        elif speaker == "evil":
            if target_value == "evil" or target_value == "lying":
                return True  # I am (evil/lying).
            else:
                return False
        else:
            if is_day:
                if target_value == "human":
                    return False
                else:
                    return True  # I am (lying/evil/divine).
            else:
                if target_value == "human" or target_value == "lying":
                    return True  # I am (human/lying).
                else:
                    return False
    else:
        if speaker == "divine" or (speaker == "human" and is_day):
            if assignment != "divine" and target_value == "divine":
                return True  # X is divine.
            elif assignment != "evil" and target_value == "evil":
                return True  # X is evil.
            elif assignment != "human" and target_value == "human":
                return True  # X is human.
            elif target_value == "lying":  # X is lying.
                if assignment == "evil" or (assignment == "human" and
                                            not is_day):
                    return False
                else:
                    return True
            else:
                return False
        else:
            if assignment == "divine" and target_value == "divine":
                return True  # X is divine.
            elif assignment == "evil" and target_value == "evil":
                return True  # X is evil.
            elif assignment == "human" and target_value == "human":
                return True  # X is human.
            elif target_value == "lying":
                if assignment == "divine" or (assignment == "human" and is_day):
                    return False
                else:
                    return True  # X is lying.
            else:
                return False


def check_assignments(assignments, conversations):
    is_day = (assignments["It"] == "day")
    for conversation in conversations:
        speaker = conversation[0]
        contents = conversation[1]
        target_person = speaker if contents[0] == "I" else contents[0]
        target_self = (contents[0] == "I")
        target_value = contents[-1]
        target_negative = (contents[-2] == "not")

        if is_lying(assignments[speaker], assignments[target_person],
                    target_value, target_self, target_negative, is_day):
            return False
    return True


def run(N):
    conversations = [parse(input()) for i in range(N)]
    speakers = ['A', 'B', 'C', 'D', 'E', 'It']

    n_possible_assignments = 2 * (3**(len(speakers) - 1))
    passing_assignments = dict([(x, set()) for x in speakers])
    possible = False
    for i in range(n_possible_assignments):
        assignments = decode_assignments(i)

        if check_assignments(assignments, conversations):
            possible = True
            for speaker in speakers:
                passing_assignments[speaker].add(assignments[speaker])

    if not possible:
        print("This is impossible.")
        return

    n_facts = 0
    for speaker in speakers:
        if len(passing_assignments[speaker]) == 1:
            n_facts += 1
            print("{} is {}.".format(speaker,
                                     list(passing_assignments[speaker])[0]))

    if n_facts == 0:
        print("No facts are deducible.")


if __name__ == '__main__':
    counter = 0
    while True:
        N = int(input())
        if N == 0:
            break
        counter += 1
        print("Conversation #{}".format(counter))
        run(N)
        print("")