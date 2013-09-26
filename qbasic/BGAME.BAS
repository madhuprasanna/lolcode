CLS
SCREEN 12
FOR I = 1 TO 1000
PRINT TAB(25); "Welcome to GAME BOARD"
LOCATE 14
LINE (160, 160)-(400, 260), 5, B
FOR J = 1 TO 500
NEXT J
NEXT I
CLS
LOCATE 14
INPUT "Enter the name of player A"; NAME1$
INPUT "Enter the name of player B"; NAME2$
CLS

REM ********************PROGRAM STARTS**********************
DIM A(100), B(100), C(100), K(1500)
DIM X(9), Y(9), COIN(9), DIST(9)
DIM R1(500), R2(500), R3(500), R4(500), R5(500), R6(500), R7(500), R8(500), R9(500)
DIM WP$(9)

REM **************************coin***********************
LINE (115, 115)-(125, 125), 15, BF
LINE (116, 116)-(125, 125), 4, BF

LINE (116, 116)-(124, 124), 12, BF
GET (115, 115)-(125, 125), A
CLS

LINE (115, 115)-(125, 125), 15, BF
LINE (116, 116)-(125, 125), 1, BF

LINE (116, 116)-(124, 124), 9, BF
GET (115, 115)-(125, 125), B
CLS

REM **************************corners********************
X(1) = 207: Y(1) = 77
X(2) = 207: Y(2) = 127
X(3) = 207: Y(3) = 177

X(4) = 257: Y(4) = 77
X(5) = 257: Y(5) = 127
X(6) = 257: Y(6) = 177

X(7) = 307: Y(7) = 77
X(8) = 307: Y(8) = 127
X(9) = 307: Y(9) = 177

FOR I = 7 TO 1 STEP -1
CIRCLE (100, 100), I, 14
NEXT I

GET (95, 95)-(105, 105), C
CLS

FOR I = 1 TO 9
PUT (X(I), Y(I)), C
NEXT I

REM **************************board**********************
LINE (210, 180)-(310, 80), 9, BF
LINE (260, 180)-(260, 80), 0
LINE (210, 130)-(310, 130), 0
LINE (210, 180)-(310, 80), 0
LINE (210, 80)-(310, 180), 0


REM *************************Corner Storage*************

GET (210, 180)-(310, 80), K
GET (X(1), Y(1))-(X(1) + 30, Y(1) + 30), R1
GET (X(2), Y(2))-(X(2) + 30, Y(2) + 30), R2
GET (X(3), Y(3))-(X(3) + 30, Y(3) + 30), R3
GET (X(4), Y(4))-(X(4) + 30, Y(4) + 30), R4
GET (X(5), Y(5))-(X(5) + 30, Y(5) + 30), R5
GET (X(6), Y(6))-(X(6) + 30, Y(6) + 30), R6
GET (X(7), Y(7))-(X(7) + 30, Y(7) + 30), R7
GET (X(8), Y(8))-(X(8) + 30, Y(8) + 30), R8
GET (X(9), Y(9))-(X(9) + 30, Y(9) + 30), R9

REM *************************placing coins*****************

FOR J = 1 TO 6

1001
LOCATE 13

IF J MOD 2 <> 0 THEN
PRINT NAME1$
INPUT "Point:"; PNT$

ELSE
PRINT NAME2$
INPUT "Point:"; PNT$
END IF

PNT = VAL(PNT$)
ON ERROR GOTO 1001

LOCATE 13
PRINT SPACE$(LEN(NAME1$ + NAME2$))

REM ***************CONDITION 1

IF PNT > 9 OR PNT < 1 THEN
BEEP
GOTO 1001
END IF

REM ****************CONDITION 2

IF COIN(PNT) = 1 THEN
BEEP
GOTO 1001
END IF

REM ****************CONDITION 3

IF INT(PNT) <> PNT THEN
BEEP
GOTO 1001
END IF

IF J MOD 2 <> 0 THEN
  WP$(PNT) = "A"
  PUT (X(PNT), Y(PNT)), A, PSET
  ELSE
  WP$(PNT) = "B"
  PUT (X(PNT), Y(PNT)), B, PSET
END IF

COIN(PNT) = 1
IF J = 5 THEN NAME$ = NAME1$
IF J = 6 THEN NAME$ = NAME2$


REM ****************CHECK WINNING

IF WP$(1) = WP$(2) AND WP$(2) = WP$(3) AND WP$(1) <> "" THEN 3001
IF WP$(1) = WP$(4) AND WP$(4) = WP$(7) AND WP$(4) <> "" THEN 3001
IF WP$(1) = WP$(5) AND WP$(5) = WP$(9) AND WP$(5) <> "" THEN 3001
IF WP$(2) = WP$(5) AND WP$(5) = WP$(8) AND WP$(2) <> "" THEN 3001
IF WP$(3) = WP$(6) AND WP$(6) = WP$(9) AND WP$(3) <> "" THEN 3001
IF WP$(4) = WP$(5) AND WP$(5) = WP$(6) AND WP$(6) <> "" THEN 3001
IF WP$(7) = WP$(5) AND WP$(5) = WP$(3) AND WP$(7) <> "" THEN 3001
IF WP$(7) = WP$(8) AND WP$(8) = WP$(9) AND WP$(8) <> "" THEN 3001

NEXT J

REM *********************Playing Section**************************

PLAY$ = "A"

WHILE 2 = 2

1002
LOCATE 13
PRINT SPACE$(LEN(NAME1$ + NAME2$) + 10)
LOCATE 13
IF PLAY$ = "A" THEN PRINT "Player "; NAME1$ ELSE PRINT "Player "; NAME2$

LOCATE 14
INPUT "From Point:"; EPNT
LOCATE 14
PRINT STRING$(80, " ")
LOCATE 14
INPUT "To   Point:"; PNT
LOCATE 14
PRINT STRING$(80, " ")

REM ***************CONDITION 1

IF EPNT > 9 OR EPNT < 1 OR PNT > 9 OR PNT < 1 THEN
BEEP
GOTO 1002
END IF

REM **************CONDITION 2

IF COIN(EPNT) <> 1 THEN
BEEP
GOTO 1002
END IF

REM **************CONDITION 3

IF COIN(PNT) = 1 THEN
BEEP
GOTO 1002
END IF

REM ***************CONDITION 4

IF EPNT = PNT THEN
BEEP
GOTO 1002
END IF

REM ****************CONDITION 5
IF INT(PNT) <> PNT OR INT(EPNT) <> EPNT THEN
BEEP
GOTO 1002
END IF

REM ******************playing conditions**********************


IF EPNT = 5 THEN
IF PNT = 1 OR PNT = 3 OR PNT = 7 OR PNT = 9 THEN 2001
END IF

IF PNT = 5 THEN
IF EPNT = 1 OR EPNT = 3 OR EPNT = 7 OR EPNT = 9 THEN 2001
END IF

DISTA = (X(EPNT) - X(PNT)) ^ 2 + (Y(EPNT) - Y(PNT)) ^ 2

FOR I = 1 TO 9
DIST(I) = (X(EPNT) - X(I)) ^ 2 + (Y(EPNT) - Y(I)) ^ 2
IF DIST(I) < DISTA AND DIST(I) <> 0 AND COIN(I) = 0 THEN
BEEP
GOTO 1002
END IF
NEXT I


2001
REM *********************SECTION FIXING************************

IF WP$(EPNT) = "A" AND PLAY$ = "A" THEN
  WP$(PNT) = "A"
  PUT (X(PNT), Y(PNT)), A, PSET
  ELSE
IF WP$(EPNT) = "B" AND PLAY$ = "B" THEN
  WP$(PNT) = "B"
  PUT (X(PNT), Y(PNT)), B, PSET
ELSE
  BEEP
  GOTO 1002
END IF

END IF

REM ********************SECTION REMOVAL******************

IF EPNT = 1 THEN
PUT (X(1), Y(1)), R1, PSET
END IF

IF EPNT = 2 THEN
PUT (X(2), Y(2)), R2, PSET
END IF

IF EPNT = 3 THEN
PUT (X(3), Y(3)), R3, PSET
END IF

IF EPNT = 4 THEN
PUT (X(4), Y(4)), R4, PSET
END IF

IF EPNT = 5 THEN
PUT (X(5), Y(5)), R5, PSET
END IF

IF EPNT = 6 THEN
PUT (X(6), Y(6)), R6, PSET
END IF

IF EPNT = 7 THEN
PUT (X(7), Y(7)), R7, PSET
END IF

IF EPNT = 8 THEN
PUT (X(8), Y(8)), R8, PSET
END IF

IF EPNT = 9 THEN
PUT (X(9), Y(9)), R9, PSET
END IF

WP$(EPNT) = ""
COIN(PNT) = 1
COIN(EPNT) = 0

REM *******************winner section***************

IF WP$(1) = WP$(2) AND WP$(2) = WP$(3) AND WP$(1) <> "" THEN 3001
IF WP$(1) = WP$(4) AND WP$(4) = WP$(7) AND WP$(4) <> "" THEN 3001
IF WP$(1) = WP$(5) AND WP$(5) = WP$(9) AND WP$(5) <> "" THEN 3001
IF WP$(2) = WP$(5) AND WP$(5) = WP$(8) AND WP$(2) <> "" THEN 3001
IF WP$(3) = WP$(6) AND WP$(6) = WP$(9) AND WP$(3) <> "" THEN 3001
IF WP$(4) = WP$(5) AND WP$(5) = WP$(6) AND WP$(6) <> "" THEN 3001
IF WP$(7) = WP$(5) AND WP$(5) = WP$(3) AND WP$(7) <> "" THEN 3001
IF WP$(7) = WP$(8) AND WP$(8) = WP$(9) AND WP$(8) <> "" THEN 3001

IF PLAY$ = "A" THEN
PLAY$ = "B"
NAME$ = NAME2$
ELSE
PLAY$ = "A"
NAME$ = NAME1$
END IF

WEND


3001
BEEP
BEEP
FOR I = 1 TO 300000
NEXT I
CLS
LOCATE 14
PRINT TAB(30); NAME$; " is the Winner "
END













