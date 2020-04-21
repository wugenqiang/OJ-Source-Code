echo '--------upload files start--------'

git add .

git status

git commit -m 'auto update https://github.com/wugenqiang/SwordForOffer.git'

echo '--------commit successfully--------'

git push -u https://github.com/wugenqiang/SwordForOffer.git master
# git push -u origin master

echo '--------push to GitHub successfully--------'
