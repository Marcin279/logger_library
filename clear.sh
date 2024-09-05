#!/bin/bash

if [ "$1" == "--test" ]; then
    if [ -e logger_library_test ]; then
        rm logger_library_test
        echo "Usunięto plik logger_library_test."
    else
        echo "Plik logger_library_test nie istnieje."
    fi
elif [ "$1" == "--run" ]; then
    if [ -e logger_library_run ]; then
        rm logger_library_run
        echo "Usunięto plik logger_library_run."
    else
        echo "Plik logger_library_run nie istnieje."
    fi
else
    echo "Użycie: $0 [--test|--run]"
fi
