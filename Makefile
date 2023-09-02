DEBUG_FLAGS   = -D _DEBUG -ggdb3 -std=c++2a -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wstack-usage=8192 -pie -fPIE -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,leak,null,OBJ-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
RELEASE_FLAGS = -O2
SFML_FLAGS    = -lsfml-graphics -lsfml-window -lsfml-system

SRC_FOLDER = Src
OBJ_FOLDER = Obj
EXE_FILE = Exe/Run

debug:
	g++ -c $(DEBUG_FLAGS) $(SRC_FOLDER)/Vector/Vector.cpp -o $(OBJ_FOLDER)/Vector.o
	g++ $(SFML_FLAGS) $(DEBUG_FLAGS) $(SRC_FOLDER)/main.cpp $(OBJ_FOLDER)/Vector.o -o $(EXE_FILE)

release:
	g++ -c $(RELEASE_FLAGS) $(SRC_FOLDER)/Vector/Vector.cpp -o $(OBJ_FOLDER)/Vector.o
	g++ $(SFML_FLAGS) $(RELEASE_FLAGS) $(SRC_FOLDER)/main.cpp $(OBJ_FOLDER)/Vector.o -o $(EXE_FILE)

run:
	./$(EXE_FILE)

preparation:
	mkdir Obj
	mkdir Exe

