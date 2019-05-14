# Level6 - bruteforce a PIN
pin.txt contains a 4-digit PIN that you must guess correctly. The possible set
of PINs is [0000, 0001, 0002, ..., 9998, 9999]. All PINs are exactly four
digits.

This level has an additional challenge: the PIN resets every hour from 8 a.m.
to 6 p.m. If you don't guess correctly before the PIN rolls over, it'll change
to a new random number.

If the correct PIN is guessed, `levelup` runs automatically.

## Tips
- While the time-sensitive nature encourages you to start guessing at the top
  of the hour, it is possible to get lucky at any point.
- Take advantage of parallelization whenever you can
