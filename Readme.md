

git init
git status

git add .
git commit -m "primer commit"

git remote add origin git@github.com:lucas-dobrovolski/Geodesic.git
git push -u origin main


find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" -o -name "*.c" -o -name "*.glsl" -o -name "Makefile" \) \
  -exec sh -c 'echo "===== FILE: {} ====="; cat "{}"; echo ""' \;


