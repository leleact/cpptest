include ~/platform/platmk/plat.mk
TARGET = lele_test_move
OBJECTS =	lele_test_move.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@
$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(OBJECTS) $(TARGET)
