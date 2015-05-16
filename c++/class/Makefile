include /home/lele/platform/platmk/plat.mk
all 	   : 	lele_test_class
main 	   = 	lele_test_class
objects    =  lele_test_class.o
$(main)  :   lele_test_class.o 
	$(CXX) $(CXXFLAGS) $< -o $@
$(objects) : %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
.PHONY     :    clean
clean:
	$(RM) $(objects) $(main)
