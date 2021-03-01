import time


def alarm(h, m, s):
    if (h == time.localtime().tm_hour):
        if m == time.localtime().tm_min:
            if s == time.localtime().tm_sec:
                return True
    return False



