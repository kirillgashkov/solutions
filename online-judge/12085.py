def calc_max_common_prefix_len(s1, s2):
    count = 0

    for i in range(min(len(s1), len(s2))):
        if s1[i] == s2[i]:
            count += 1
        else:
            break

    return count


def print_start_and_last_numbers(start_number, last_number):
    start = '0' + str(start_number)
    last = '0' + str(last_number)

    if start == last:
        print(start)
        return

    common_prefix_len = calc_max_common_prefix_len(start, last)
    print(start + '-' + last[common_prefix_len:])


def handle_case(n):
    if n == 1:
        print(input())
        return

    start_number = None
    last_number = None

    for _ in range(n):
        number = int(input())

        if start_number is None:
            start_number = number
            last_number = number
            continue

        if number - last_number == 1:
            last_number = number
        else:
            print_start_and_last_numbers(start_number, last_number)
            start_number = number
            last_number = number

    print_start_and_last_numbers(start_number, last_number)


def main():
    case_number = 0

    while True:
        case_number += 1

        n = int(input())
        if n == 0:
            break

        print('Case %d:' % case_number)
        handle_case(n)
        print()


main()
