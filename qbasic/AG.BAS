CLS
SCREEN 7
COLOR 1

COLOUR = 5
COLOUR2 = 4

SPEED = 5
SPEED2 = 15

DIM A(1 TO 300), B(1 TO 300), C(1 TO 400), D(1 TO 400), G(1 TO 100)
DIM A3(1 TO 300), B3(1 TO 300), C3(1 TO 400), D3(1 TO 400), G3(1 TO 100)

REM ********************MY SHIP************************


REM ********************UP
CLS
LINE (100, 100)-(128, 120), COLOUR, BF
LINE (110, 94)-(118, 97), COLOUR, BF
LINE (114, 94)-(114, 100), COLOUR, B
GET (90, 90)-(140, 130), A
CLS

REM ********************DOWN
CLS
LINE (100, 100)-(128, 120), COLOUR, BF
LINE (110, 123)-(118, 126), COLOUR, BF
LINE (114, 120)-(114, 126), COLOUR, B
GET (90, 90)-(140, 130), B
CLS

REM *********************LEFT
CLS
LINE (100, 100)-(128, 120), COLOUR, BF
LINE (94, 106)-(97, 114), COLOUR, BF
LINE (94, 110)-(100, 110), COLOUR, B
GET (90, 90)-(130, 140), C
CLS

REM *********************RIGHT
CLS
LINE (100, 100)-(128, 120), COLOUR, BF
LINE (131, 106)-(134, 114), COLOUR, BF
LINE (128, 110)-(131, 110), COLOUR, B
GET (90, 90)-(140, 130), D
CLS

REM ********************MY GUN
CLS
CIRCLE (100, 100), 5, 5
LINE (95, 100)-(105, 100), 1
LINE (100, 96)-(100, 104), 1
GET (95, 95)-(105, 105), G
CLS

REM ********************ENEMY SHIP*********************

REM ********************UP
CLS
LINE (100, 100)-(128, 120), COLOUR2, BF
LINE (110, 94)-(118, 97), COLOUR2, BF
LINE (114, 94)-(114, 100), COLOUR2, B
GET (90, 90)-(140, 130), A3
CLS

REM *********************DOWN
CLS
LINE (100, 100)-(128, 120), COLOUR2, BF
LINE (110, 123)-(118, 126), COLOUR2, BF
LINE (114, 120)-(114, 126), COLOUR2, B
GET (90, 90)-(140, 130), B3
CLS

REM *********************LEFT
CLS
LINE (100, 100)-(128, 120), COLOUR2, BF
LINE (94, 106)-(97, 114), COLOUR2, BF
LINE (94, 110)-(100, 110), COLOUR2, B
GET (90, 90)-(130, 140), C3
CLS

REM ********************RIGHT
CLS
LINE (100, 100)-(128, 120), COLOUR2, BF
LINE (131, 106)-(134, 114), COLOUR2, BF
LINE (128, 110)-(131, 110), COLOUR2, B
GET (90, 90)-(140, 130), D3
CLS

REM ********************ENEMY GUN
CLS
CIRCLE (100, 100), 6, 6
LINE (95, 100)-(105, 100), 2
LINE (100, 96)-(100, 104), 2
GET (95, 95)-(105, 105), G3
CLS

X1 = 90: Y1 = 90: E1 = 1: M = 1
PUT (X1, Y1), A3, XOR


REM ********************MY MOVE********************

X = 90: Y = 90: E = 1
PUT (X, Y), A, XOR
80 X$ = INKEY$
GOSUB 280
90 IF X$ = "" THEN 80

IF Y <= 10 THEN Y = 10
IF Y >= 140 THEN Y = 140
IF X <= 10 THEN X = 10
IF X >= 250 THEN X = 250

92 IF X$ = CHR$(13) THEN 170: REM  CHR$(13) is ENTER

CLS

100 IF X$ = MKI$(18432) THEN Y = Y - 10: PUT (X, Y), A, XOR: E = 1: A1 = X + 24: B1 = Y - 1: C1 = A1: D1 = 1
110 IF X$ = MKI$(20480) THEN Y = Y + 10: PUT (X, Y), B, XOR: E = 2: A1 = X + 24: B1 = Y + 41: C1 = A1: D1 = 170
120 IF X$ = MKI$(19200) THEN X = X - 10: PUT (X, Y), C, XOR: E = 3: A1 = X - 1: B1 = Y + 20: C1 = 1: D1 = B1
130 IF X$ = MKI$(19712) THEN X = X + 10: PUT (X, Y), D, XOR: E = 4: A1 = X + 49: B1 = Y + 20: C1 = 300: D1 = B1
140 IF X$ = CHR$(27) THEN END
160 GOTO 80

170 ON E GOTO 180, 190, 200, 210
180 FOR I = B1 TO D1 STEP -1
FOR J = 1 TO SPEED
PUT (A1 - 5, I), G, XOR
PUT (A1 - 5, I), G, XOR
NEXT J
NEXT I
GOTO 80
190 FOR I = B1 TO D1
FOR J = 1 TO SPEED
PUT (A1 - 5, I), G, XOR
PUT (A1 - 5, I), G, XOR
NEXT J
NEXT I
GOTO 80
200 FOR I = A1 TO C1 STEP -1
FOR J = 1 TO SPEED
PUT (I, B1 - 5), G, XOR
PUT (I, B1 - 5), G, XOR
NEXT J
NEXT I
GOTO 80
210 FOR I = A1 TO C1
FOR J = 1 TO SPEED
PUT (I, B1 - 5), G, XOR
PUT (I, B1 - 5), G, XOR
NEXT J
NEXT I
GOTO 80

REM THIS PART OF THE PROGRAM IS TO MOVE THE ENEMY SHIP AT RANDOM.

280 IF P = 10 THEN P = 1 ELSE P = P + 1: RETURN

M1 = M1 + 1
IF M1 <= M THEN 290
M1 = 0
RANDOMIZE TIMER
R = 1 + FIX(RND * 4): M = 1 + FIX(RND * 100)
290 ON R GOTO 911, 912, 913, 914, 915
911 X1$ = MKI$(18432): GOTO 916
912 X1$ = MKI$(20480): GOTO 916
913 X1$ = MKI$(19200): GOTO 916
914 X1$ = MKI$(19712): GOTO 916
915 X1$ = CHR$(13): GOTO 916
916 IF Y1 <= 1 THEN Y1 = 1
IF Y1 >= 150 THEN Y1 = 140
IF X1 <= 1 THEN X1 = 1
IF X1 >= 260 THEN X1 = 260
292 IF X1$ = CHR$(13) THEN 370
293 ON E1 GOTO 295, 296, 297, 298
295 PUT (X1, Y1), A3, XOR: GOTO 300
296 PUT (X1, Y1), B3, XOR: GOTO 300
297 PUT (X1, Y1), C3, XOR: GOTO 300
298 PUT (X1, Y1), D3, XOR: GOTO 300
300 IF X1$ = MKI$(18432) THEN Y1 = Y1 - 1:  PUT (X1, Y1), A3, XOR: E1 = 1: A2 = X1 + 24: B2 = Y1 - 1: C2 = A2: D2 = 1
310 IF X1$ = MKI$(20480) THEN Y1 = Y1 + 1:  PUT (X1, Y1), B3, XOR: E1 = 2: A2 = X1 + 24: B2 = Y1 + 41: C2 = A2: D2 = 170
320 IF X1$ = MKI$(19200) THEN X1 = X1 - 1:  PUT (X1, Y1), C3, XOR: E1 = 3: A2 = X1 - 1: B2 = Y1 + 20: C2 = 1: D2 = B2
330 IF X1$ = MKI$(19712) THEN X1 = X1 + 1:  PUT (X1, Y1), D3, XOR: E1 = 4: A2 = X1 + 49: B2 = Y1 + 20: C2 = 300: D2 = B2
340 IF X1$ = CHR$(27) THEN END
360 RETURN
370 ON E1 GOTO 380, 390, 400, 410
380 FOR I = B2 TO D2 STEP -1
FOR J = 1 TO SPEED2
PUT (A2 - 5, I), G3, XOR
PUT (A2 - 5, I), G3, XOR
NEXT J
NEXT I
RETURN
390 FOR I = B2 TO D2
FOR J = 1 TO SPEED2
PUT (A2 - 5, I), G3, XOR
PUT (A2 - 5, I), G3, XOR
NEXT J
NEXT I
RETURN
400 FOR I = A2 TO C2 STEP -1
FOR J = 1 TO SPEED2
PUT (I, B2 - 5), G3, XOR
PUT (I, B2 - 5), G3, XOR
NEXT J
NEXT I
RETURN
410 FOR I = A2 TO C2
FOR J = 1 TO SPEED2
PUT (I, B2 - 5), G3, XOR
PUT (I, B2 - 5), G3, XOR
NEXT J
NEXT I
RETURN

