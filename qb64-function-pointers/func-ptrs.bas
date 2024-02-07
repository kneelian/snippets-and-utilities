DECLARE CUSTOMTYPE LIBRARY "test"
    SUB EXTERNAL ()
    FUNCTION EXT2%& ()
    FUNCTION EXT3%& ()
    SUB EXT4 (BYVAL A AS _UNSIGNED _OFFSET)
END DECLARE

PRINT "normal"
EXTERNAL
DIM E AS _UNSIGNED _OFFSET
DIM F AS _UNSIGNED _OFFSET
E = EXT2
F = EXT3
EXT4 (E)
EXT4 (F)
END 0

PRINT "and you should never see me"

FUNCTION printboy
    PRINT "hi im printboy"
END FUNCTION

SUB printman
    PRINT "and im printman located at", EXT3
END SUB

SUB printfather
    PRINT "and im the printfather and my address is", EXT2
END SUB
