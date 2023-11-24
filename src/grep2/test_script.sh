#!/bin/bash

# Укажите путь к  программе
PATH_PROGRAM="./s21_grep"
# Укажите путь к утилите grep
GREP="grep"

# Папка с тестовыми файлами
TEST_DIR=""
# Папка для результатов  программы
OUTPUT_DIR="../common/test_grep/output"
# Папка для результатов утилиты grep
GREP_OUTPUT_DIR="../common/test_grep/grep_output"

# Создаем папки для результатов, если их нет
mkdir -p "$OUTPUT_DIR"
mkdir -p "$GREP_OUTPUT_DIR"

FLAGS_TO_TEST=("-e" "-i" "-v" "-c" "-l" "-n" "-h" "-s" "-o")
FILE="test.txt"
PATTERN="t..t"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    echo "$PATH_PROGRAM $FLG $PATTERN \"$FILE\" > \"$OUTPUT_DIR/$FILE\""
    $PATH_PROGRAM $FLG $PATTERN "$FILE" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    echo "$GREP $FLG $PATTERN \"$FILE\" > \"$GREP_OUTPUT_DIR/$FILE\""
    $GREP $FLG $PATTERN "$FILE" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo -e "File testing $FILE with flags $FLG -> \e[32msuccess\e[0m"
    else
      echo -e "File testing $FILE with flags $FLG -> \e[31mfail\e[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"

done

FLG="-f"
PATTERN="../common/test_files/pattern.txt"

# Тестируем программу
    echo "$PATH_PROGRAM $FLG $PATTERN \"$FILE\" > \"$OUTPUT_DIR/$FILE\""
    $PATH_PROGRAM $FLG $PATTERN "$FILE" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    echo "$GREP $FLG $PATTERN \"$FILE\" > \"$GREP_OUTPUT_DIR/$FILE\""
    $GREP $FLG $PATTERN "$FILE" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo -e "File testing $FILE with flags $FLG -> \e[32msuccess\e[0m"
    else
      echo -e "File testing $FILE with flags $FLG -> \e[31mfail\e[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"

FLAGS_TO_TEST=("-iv" "-ic" "-in" 
"-ih" "-vc" "-vn" "-vh" "-vs" "-vo" "-cl" "-cn" "-ch" "-cs" 
"-co" "-ln" "-lh" "-ls" "-lo" "-nh" "-ns" "-no" "-hs" "-ho" 
"-so" "-ivc" "-ivl" "-ivn" "-ivh" "-ivs" "-ivo" "-icl" "-icn" 
"-ich" "-ics" "-ico" "-iln" "-ilh" "-ils" "-ilo" "-inh" "-ins" 
"-ihs" "-vcl" "-vcn" "-vch" "-vcs" "-vco" "-nho" "-nso" "-hso" 
"-vln" "-vlh" "-vls" "-vlo" "-vnh" "-vns" "-vno" "-vhs" "-vho" 
"-vso" "-cln" "-clh" "-cls" "-clo" "-cnh" "-cns" "-cno" "-chs" 
"-cho" "-cso" "-lnh" "-lns" "-lno" "-lhs" "-lho" "-lso" "-nhs")
FILE="test.txt"
PATTERN="t..t"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM $FLG $PATTERN "$FILE" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP $FLG $PATTERN "$FILE" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo -e "File testing $FILE with flags $FLG -> \e[32msuccess\e[0m"
    else
      echo -e "File testing $FILE with flags $FLG -> \e[31mfail\e[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"
done

FLAGS_TO_TEST=("-v" "-c" "-n" "-h" "-vc" "-vn" 
"-vh" "-vs" "-vo" "-cl" "-cn" "-cs" "-co" "-ln" "-lh" 
"-ls" "-lo" "-nh" "-ns" "-hs" "-ivl" "-vcl" "-vcn" "-vcs" 
"-vco" "-vln" "-vlh" "-vls" "-vlo" "-vnh" "-vns" 
"-vno" "-vhs" "-vho" "-vso" "-cln" "-cls" "-clo" 
"-cns" "-cno" "-cso" "-lnh" "-lns" "-lno" 
"-lhs" "-lho" "-lso" "-nhs")

FILE="test.txt"
FILE2="test2.txt"
PATTERN="t..t"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM $FLG $PATTERN "$FILE" "$FILE2" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP $FLG $PATTERN "$FILE" "$FILE2" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo -e "File testing $FILE and $FILE2 with flags $FLG -> \e[32msuccess\e[0m"
    else
      echo -e "File testing $FILE and $FILE2 with flags $FLG -> \e[31mfail\e[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"
done

FILE="test.txt"
FILE2="test.txt"
PATTERN="t..t"
PATTERN2="1"

for FLG in "${FLAGS_TO_TEST[@]}"
do
    # Тестируем программу
    $PATH_PROGRAM -e $PATTERN -e $PATTERN2 $FLG "$FILE" "$FILE2" > "$OUTPUT_DIR/$FILE"

    # Тестируем утилиту grep
    $GREP -e $PATTERN -e $PATTERN2 $FLG "$FILE" "$FILE2" > "$GREP_OUTPUT_DIR/$FILE"

    # Сравниваем результаты
    diff "$OUTPUT_DIR/$FILE" "$GREP_OUTPUT_DIR/$FILE" > /dev/null
    if [ $? -eq 0 ]; then
      echo -e "File testing $FILE and $FILE2 with flags $FLG and templates [$PATTERN], [$PATTERN2] (by flag -e)  -> \e[32msuccess\e[0m"
    else
      echo -e "File testing $FILE and $FILE2 with flags $FLG and templates [$PATTERN], [$PATTERN2] (by flag -e) -> \e[31mfail\e[0m"
    fi
    rm -rf "$OUTPUT_DIR/$FILE"
    rm -rf "$GREP_OUTPUT_DIR/$FILE"
done
