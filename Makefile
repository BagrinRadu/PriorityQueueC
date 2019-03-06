CFLAGS=/nologo /W4 /EHsc /Za

build: tema1.exe

tema1.exe: tema1.obj
	cl /MD /Wall compare.lib tema1.obj /Fetema1.exe

tema1.obj: tema1.c
	cl /c /Wall tema1.c


#lib /def:compare.dll /out:compare.lib

clean:
	del *.obj *.exe