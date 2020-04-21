echo '--------upload files start--------'

git add .

git status

git commit -m 'auto update upload'

echo '--------commit successfully--------'

git push -u https://github.com/wugenqiang/OJ-Source-Code.git master
# git push -u origin master

echo '--------push to GitHub successfully--------'
