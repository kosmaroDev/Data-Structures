# Directories
MAIN = main
TEST = test
# Generics
APPS = apps
TESTS = tests
BIN = bin
INCLUDE = include
LIB = lib
OBJ = obj
SRC = src
#--ADD_FOLDER_NEW_HELPER
#--ADD_FOLDER_NEW_DS

# Names Definition
APP_NAME = app_circular_doubly_linked_list
LIB_NAME = cdll
DS = circular_doubly_linked_list
TEST_DS = circular_doubly_linked_list.test
UNITY = ../../resources/unity
DEPS = ../../resources/scripts/dependencies
#--ADD_NEW_HELPER
#--ADD_NEW_DS
#DS0
#H0

# Compilation Flags
FLAGS = -O3 -Wall -pedantic -Warray-bounds -Werror
LIBS = -l$(LIB_NAME) -L $(MAIN)/$(LIB)

--private-create_folders:
	mkdir $(MAIN)/$(LIB)
	mkdir $(MAIN)/$(OBJ)
	mkdir $(MAIN)/$(BIN)
	mkdir $(TEST)/$(BIN)

--private-get_unity:
#--ADD_GET_NEW_LIB
	cp $(UNITY)/$(INCLUDE)/* $(MAIN)/$(INCLUDE)/
	cp $(UNITY)/$(SRC)/* $(MAIN)/$(SRC)/

pack: clean_all --private-create_folders --private-get_unity \
	$(MAIN)/$(OBJ)/$(DS).o \
#--ADD_TO_PACK
	ar -rcs $(MAIN)/$(LIB)/lib$(LIB_NAME).a $(MAIN)/$(OBJ)/*.o

compile_apps: $(MAIN)/$(BIN)/$(APP_NAME)

compile_test: $(MAIN)/$(OBJ)/$(DS).o \
	$(MAIN)/$(OBJ)/unity.o \
 	$(TEST)/$(BIN)/$(TEST_DS) \
#--ADD_TO_COMPILE_TEST

run_apps: pack compile_apps
	$(MAIN)/$(BIN)/$(APP_NAME)
	make clean_unity

run_tests: clean_all pack compile_test
	$(TEST)/$(BIN)/$(TEST_DS)
	make clean_all

add_deps:
	$(DEPS)/add_deps.sh

get_deps:
	$(DEPS)/get_deps.sh

clean_all: clean_libs clean_apps clean_test clean_unity

clean_libs:
	rm -rf $(MAIN)/$(OBJ) $(MAIN)/$(LIB)

clean_apps:
	rm -rf $(MAIN)/$(BIN)

clean_test:
	rm -rf $(TEST)/$(BIN)

clean_unity:
#--ADD_TO_CLEAN
	rm -rf $(MAIN)/$(SRC)/unity.c
	rm -rf $(MAIN)/$(INCLUDE)/unity.h
	rm -rf $(MAIN)/$(INCLUDE)/unity_internals.h

$(MAIN)/$(OBJ)/%.o: $(MAIN)/$(SRC)/%.c $(MAIN)/$(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(MAIN)/$(INCLUDE) -o $@

$(MAIN)/$(BIN)/%: $(MAIN)/$(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(MAIN)/$(INCLUDE) -o $@

$(TEST)/$(BIN)/%: $(TEST)/$(TESTS)/%.c
	gcc $(FLAGS) $< $(MAIN)/$(OBJ)/*.o -I $(MAIN)/$(INCLUDE) -o $@