CC : gcc
CFlags : -W -Wall
TARGET = product
DTARGET = product_debug
OBJECTS = product.o manager.o  market.o 

$(TARGET) : $(OBJECTS)
	$(CC) $(CFlags) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFlags) -DDEBUG -o $@ $^

clean : 
	rm *.o product $(TARGET) $(DTARGET)
