cd ..

if [[ $# -eq 0 ]] ; then
	rm -rf _build
fi

mkdir _build
cd _build
cmake .. -GXcode