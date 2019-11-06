import datetime


ZODIAC_DATE_STRS = {
    'Aquarius': ('January, 21', 'February, 19'),
    'Pisces': ('February, 20', 'March, 20'),
    'Aries': ('March, 21', 'April, 20'),
    'Taurus': ('April, 21', 'May, 21'),
    'Gemini': ('May, 22', 'June, 21'),
    'Cancer': ('June, 22', 'July, 22'),
    'Leo': ('July, 23', 'August, 21'),
    'Virgo': ('August, 22', 'September, 23'),
    'Libra': ('September, 24', 'October, 23'),
    'Scorpio': ('October, 24', 'November, 22'),
    'Sagittarius': ('November, 23', 'December, 22'),
    'Capricorn': ('December, 23', 'January, 20'),
}


# also make all zodiacs lowercase
ZODIAC_DATES = {
    zodiac.lower(): (
        datetime.datetime.strptime(date_strs[0], '%B, %d'),
        datetime.datetime.strptime(date_strs[1], '%B, %d'),
    )
    for zodiac, date_strs in ZODIAC_DATE_STRS.items()
}
ZODIAC_DATES['capricorn'] = (
    datetime.datetime(year=1899, month=12, day=23),
    datetime.datetime(year=1900, month=1, day=20),
)


def _determine_zodiac(date):
    date_to_compare = datetime.datetime(year=1900, month=date.month, day=date.day)

    for zodiac, (from_date, to_date) in ZODIAC_DATES.items():
        if from_date <= date_to_compare <= to_date:
            return zodiac

    return None


def handle_case(case_number):
    start_date_str = input()
    start_date = datetime.datetime.strptime(start_date_str, '%m%d%Y')

    end_date = start_date + datetime.timedelta(weeks=40)
    end_date_str = end_date.strftime('%m/%d/%Y')

    print(case_number, end_date_str, _determine_zodiac(end_date))


def main():
    cases_n = int(input())

    for case_number in range(1, cases_n + 1):
        handle_case(case_number)


main()
