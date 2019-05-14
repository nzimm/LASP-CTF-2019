#!/usr/bin/env python3
import random

def main():
    random.seed()
    pin = random.randint(0,9999)
    print(str(pin).zfill(4))
    return 0

if __name__ == '__main__':
    exit(main())
