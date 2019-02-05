set /p message="enter message: "
git add *
git commit -m "%message%"
git push
pause