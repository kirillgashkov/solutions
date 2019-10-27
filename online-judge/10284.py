from sys import stdin


ATTACKED = '*'


def row_desc_to_row(row_desc):
    row = list()

    for element in row_desc:
        if element.isnumeric():
            row += [None] * int(element)
        else:
            row.append(element)

    return row


def is_piece(piece):
    return piece is not None and piece != ATTACKED


def mark_ray_straight(i, j, field):
    # up
    mark_i = i

    while mark_i > 0:
        mark_i -= 1
        if is_piece(field[mark_i][j]):
            break
        field[mark_i][j] = ATTACKED

    # down
    mark_i = i

    while mark_i < 7:
        mark_i += 1
        if is_piece(field[mark_i][j]):
            break
        field[mark_i][j] = ATTACKED

    # left
    mark_j = j

    while mark_j > 0:
        mark_j -= 1
        if is_piece(field[i][mark_j]):
            break
        field[i][mark_j] = ATTACKED

    # right
    mark_j = j

    while mark_j < 7:
        mark_j += 1
        if is_piece(field[i][mark_j]):
            break
        field[i][mark_j] = ATTACKED


def mark_ray_diag(i, j, field):
    # left up
    mark_i = i
    mark_j = j

    while mark_i > 0 and mark_j > 0:
        mark_i -= 1
        mark_j -= 1
        if is_piece(field[mark_i][mark_j]):
            break
        field[mark_i][mark_j] = ATTACKED

    # right up
    mark_i = i
    mark_j = j

    while mark_i > 0 and mark_j < 7:
        mark_i -= 1
        mark_j += 1
        if is_piece(field[mark_i][mark_j]):
            break
        field[mark_i][mark_j] = ATTACKED

    # left down
    mark_i = i
    mark_j = j

    while mark_i < 7 and mark_j > 0:
        mark_i += 1
        mark_j -= 1
        if is_piece(field[mark_i][mark_j]):
            break
        field[mark_i][mark_j] = ATTACKED

    # right down
    mark_i = i
    mark_j = j

    while mark_i < 7 and mark_j < 7:
        mark_i += 1
        mark_j += 1
        if is_piece(field[mark_i][mark_j]):
            break
        field[mark_i][mark_j] = ATTACKED


def mark_knight(i, j, field):
    i_list = [i - 2, i - 2, i - 1, i - 1, i + 1, i + 1, i + 2, i + 2]
    j_list = [j - 1, j + 1, j - 2, j + 2, j - 2, j + 2, j - 1, j + 1]

    for mark_i, mark_j in zip(i_list, j_list):
        if mark_i > 7 or mark_i < 0 or mark_j > 7 or mark_j < 0:
            continue
        if is_piece(field[mark_i][mark_j]):
            continue
        field[mark_i][mark_j] = ATTACKED


def mark_king(i, j, field):
    i_list = [i - 1, i - 1, i - 1, i, i, i + 1, i + 1, i + 1]
    j_list = [j - 1, j, j + 1, j - 1, j + 1, j - 1, j, j + 1]

    for mark_i, mark_j in zip(i_list, j_list):
        if mark_i > 7 or mark_i < 0 or mark_j > 7 or mark_j < 0:
            continue
        if is_piece(field[mark_i][mark_j]):
            continue
        field[mark_i][mark_j] = ATTACKED


def mark_pawn_go_up(i, j, field):
    i_list = [i - 1, i - 1]
    j_list = [j - 1, j + 1]

    for mark_i, mark_j in zip(i_list, j_list):
        if mark_i > 7 or mark_i < 0 or mark_j > 7 or mark_j < 0:
            continue
        if is_piece(field[mark_i][mark_j]):
            continue
        field[mark_i][mark_j] = ATTACKED


def mark_pawn_go_down(i, j, field):
    i_list = [i + 1, i + 1]
    j_list = [j - 1, j + 1]

    for mark_i, mark_j in zip(i_list, j_list):
        if mark_i > 7 or mark_i < 0 or mark_j > 7 or mark_j < 0:
            continue
        if is_piece(field[mark_i][mark_j]):
            continue
        field[mark_i][mark_j] = ATTACKED


def handle_case(row_descs):
    rows = list(map(row_desc_to_row, row_descs))

    for i in range(8):
        for j in range(8):
            if not is_piece(rows[i][j]):
                continue

            piece = rows[i][j].lower()
            if piece == 'r':
                mark_ray_straight(i, j, rows)
            elif piece == 'n':
                mark_knight(i, j, rows)
            elif piece == 'b':
                mark_ray_diag(i, j, rows)
            elif piece == 'q':
                mark_ray_straight(i, j, rows)
                mark_ray_diag(i, j, rows)
            elif piece == 'k':
                mark_king(i, j, rows)
            elif rows[i][j] == 'p':
                # black. Going down
                mark_pawn_go_down(i, j, rows)
            elif rows[i][j] == 'P':
                # white. Going up
                mark_pawn_go_up(i, j, rows)


    none_count = 0

    for i in range(8):
        for j in range(8):
            if rows[i][j] is None:
                none_count += 1

    print(none_count)


for line in stdin:
    row_descs = line.split('/')
    handle_case(row_descs)
