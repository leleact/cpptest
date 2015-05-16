include ~/platform/platmk/plat.mk
TARGET = lele_test_func
OBJECTS = lele_test_func.o
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJECTS) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJECTS)
