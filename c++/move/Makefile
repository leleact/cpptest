include ~/platform/platmk/plat.mk
TARGET = lele_test_move lele_test_str_move
OBJECTS =	lele_test_move.o lele_test_str_move.o
all : $(TARGET)

.PHONY : all

lele_test_move : lele_test_move.o
	$(CXX) $(CXXFLAGS) $< -o $@

lele_test_str_move : lele_test_str_move.o
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : clean

clean:
	$(RM) $(OBJECTS) $(TARGET)
