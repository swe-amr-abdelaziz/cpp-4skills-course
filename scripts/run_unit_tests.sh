#!/bin/bash

directories=$(find . -mindepth 2 -maxdepth 2 -type d | grep '/section_[^/]*')

while IFS= read -r directory; do
    if [ -d "$directory" ]; then
        cd $directory
        make -f ../../Makefile run-test > /dev/null 2>&1
        RESULT=$?
        if [ $RESULT -eq 0 ]; then
            echo -en "\e[32m✅ Tests passed in directory: $directory\e[0m\n"
        else
            echo -en "\e[31m❌ Tests failed in directory: $directory\e[0m\n"
            exit $RESULT
        fi
        cd ../..
    else
        echo "Directory not found: $directory"
    fi
done <<< "$directories"

echo -en "\n\e[32m✅ All tests passed.\e[0m\n"

exit $RESULT
