include ~/platform/platmk/plat.mk
all :	lele_test_auto
lele_test_auto = lele_test_auto
objects =	lele_test_auto.o
$(lele_test_auto) : $(objects)
	$(CXX) $(CXXFLAGS) $< -o $@
$(objects) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY : clean
clean:
	$(RM) $(objects) $(lele_test_auto)
