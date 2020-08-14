#counter of test cases
number=1

# Colors
Color_Off='\033[0m'
IBlue='\033[0;94m'
IYellow='\033[0;93m'

# Test cases
EXP1="./testing/case#1"
EXP2="./testing/case#2"
EXP3="./testing/case#3"
EXP4="./testing/case#4"
EXP5="./testing/case#5"
EXP6="./testing/case#6"
EXP7="./testing/case#7"
EXP8="./testing/case#8"
EXP9="./testing/case#9"
EXP10="./testing/case#10"
EXP11="./testing/case#11"
EXP12="./testing/case#12"
EXP13="./testing/case#13"
EXPsectionDoesntExist="./testing/case#SectionDoesntExist"

#Before start
./owo clean

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (print help text)${Color_Off}"
diff -u -s $EXP1 <(./owo help)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (initialize document.txt))${Color_Off}"
./owo init
diff -u -s $EXP2 <(ls)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (clean document.txt)${Color_Off}"
./owo clean
diff -u -s $EXP3 <(ls)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (initialize owo again)${Color_Off}"
./owo init
diff -u -s $EXP4 <(./owo init)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (add section)${Color_Off}"
./owo add first
diff -s document.txt $EXP5
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (add more sections)${Color_Off}"
./owo add second
./owo add third
./owo add fourth
diff -s document.txt $EXP6
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (add text to section by id)${Color_Off}"
./owo add 2 "ahoj"
diff -s document.txt $EXP7
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (add text to section by name)${Color_Off}"
./owo add first "dalsi text na test"
diff -s document.txt $EXP8
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (add more texts to section)${Color_Off}"
./owo add second "run all tests"
./owo add second "NO duplicates"
./owo add 1 "express programer means good names atd"
./owo add 1 "minimalize classes, methods, functions"
./owo add 3 "tesssssss"
./owo add fourth "lalalal"
diff -s document.txt $EXP9
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (print sections)${Color_Off}"
diff -u -s $EXP10 <(./owo print --sections)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (same section name)${Color_Off}"
diff -u -s $EXP11 <(./owo add second)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (delete section by id)${Color_Off}"
./owo delete 0
diff -s document.txt $EXP12
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (delete section by name)${Color_Off}"
./owo delete third
diff -s document.txt $EXP13
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (delete section by id)${Color_Off}"
diff -s $EXPsectionDoesntExist <(./owo delete 4)
((number++))

echo -e "${IYellow}\tCase ${IBlue}#$number${IYellow} (delete section by name)${Color_Off}"
diff -s $EXPsectionDoesntExist <(./owo delete third)
((number++))

#./owo delete 0 1
#dodelat kontroly na odstranovani mimo velikost

./owo add git
./owo add git "git init                 - initialize repository"
./owo add git "git status               - check state of the project"
./owo add git "git add <files>          - add files to git for tracking"
./owo add git "git commit -m <comment>  - commit files"
./owo add git "git log                  - history of commits"
./owo add git "git diff                 - differences between 2 files"
./owo add git "git checkout -- <file>   - restore file from last commit" 
./owo add git "git checkout <hash>      - restore that commit"
./owo add git "git checkout master      - restore last commit"
./owo add git "git undo last commit     - delete last commit"
./owo add git "git clone <url> <folder> - clone repository to folder from remote server"
