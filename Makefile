SOURCE=main.cpp
FILE_NAME=Lab5

main:
	[ ! -d "build" ] && mkdir build; \
	g++ -o build/$(FILE_NAME) $(SOURCE)

clean:
	rm -rf build