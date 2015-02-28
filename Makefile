CC=gcc
LIBCOMP=ranlib
LIBCOMPA=ar rc
LIBS= #-lpcre  `pcre-config --libs`
EXECUTABLE=tact
SOURCES=main.c tact.c
OBJECTS=main.o
OBJECTSLIB=tact.o
#libpcre3-dev -ok
#libpcrecpp0 -ok

SOPTS=  -O3 -nostdinc -fverbose-asm -fno-builtin -nostartfiles -nostdlib #-lcurl -lmysqlclient # -w -fPIC

all:
	make clear
	$(CC) -c -w -D __NO_DEBUG -D __NO_START $(SOURCES)
	$(LIBCOMPA) lib$(EXECUTABLE).a $(OBJECTSLIB)
	$(LIBCOMP) lib$(EXECUTABLE).a
	make break
	$(CC) -c -w -D __NO_DEBUG -D __NO_START $(SOURCES)
	$(CC) -shared $(SOPTS) -o $(EXECUTABLE).so $(OBJECTSLIB)	
	make break
	$(CC) -c -w -D __NO_DEBUG -D __NO_START $(SOURCES)
	$(CC) $(SOPTS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)
	make break
test:
	make clear
	$(CC) -c -w $(SOURCES)
	$(CC) $(SOPTS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)
	strip -s ./$(EXECUTABLE)
	#strip ./$(EXECUTABLE) -R .dtors #-lpcre requires .dtors          
	#strip ./$(EXECUTABLE) -R .jcr 
	#strip ./$(EXECUTABLE) -R .got 
	#strip ./$(EXECUTABLE) -R .data
	#strip ./$(EXECUTABLE) -R .comment          
	#strip ./$(EXECUTABLE) -R .debug_aranges    
	#strip ./$(EXECUTABLE) -R .debug_pubnames   
	#strip ./$(EXECUTABLE) -R .debug_info       
	#strip ./$(EXECUTABLE) -R .debug_abbrev     
	#strip ./$(EXECUTABLE) -R .debug_line       
	#strip ./$(EXECUTABLE) -R .debug_str        
	#strip ./$(EXECUTABLE) -R .debug_loc        
	#strip ./$(EXECUTABLE) -R .debug_pubtypes   
	#strip ./$(EXECUTABLE) -R .shstrtab         
	#strip ./$(EXECUTABLE) -R .symtab           
	#strip ./$(EXECUTABLE) -R .strtab
	#strip ./$(EXECUTABLE) -R .note.ABI-tag     
	#strip ./$(EXECUTABLE) -R .gnu.hash
	#strip ./$(EXECUTABLE) -R .gnu.version  
	#strip ./$(EXECUTABLE) -R .rel.dyn 
	./$(EXECUTABLE) "arg1" "arg2"

testlog:
	make clear
	$(CC) -c -w $(SOURCES)
	$(CC) $(SOPTS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)
	strace ./$(EXECUTABLE) "arg1" "arg2"
testasm:
	make clear
	$(CC) -c -w $(SOURCES)
	$(CC) $(SOPTS) -o $(EXECUTABLE) $(OBJECTS) $(LIBS)
	./$(EXECUTABLE)
	strip -s ./$(EXECUTABLE)
	strip ./$(EXECUTABLE) -R .dtors            
	strip ./$(EXECUTABLE) -R .jcr 
	strip ./$(EXECUTABLE) -R .got 
	strip ./$(EXECUTABLE) -R .data
	strip ./$(EXECUTABLE) -R .comment          
	strip ./$(EXECUTABLE) -R .debug_aranges    
	strip ./$(EXECUTABLE) -R .debug_pubnames   
	strip ./$(EXECUTABLE) -R .debug_info       
	strip ./$(EXECUTABLE) -R .debug_abbrev     
	strip ./$(EXECUTABLE) -R .debug_line       
	strip ./$(EXECUTABLE) -R .debug_str        
	strip ./$(EXECUTABLE) -R .debug_loc        
	strip ./$(EXECUTABLE) -R .debug_pubtypes   
	strip ./$(EXECUTABLE) -R .shstrtab         
	strip ./$(EXECUTABLE) -R .symtab           
	strip ./$(EXECUTABLE) -R .strtab
	strip ./$(EXECUTABLE) -R .note.ABI-tag     
	strip ./$(EXECUTABLE) -R .gnu.hash
	strip ./$(EXECUTABLE) -R .gnu.version  
	strip ./$(EXECUTABLE) -R .rel.dyn 
	objdump -d ./$(EXECUTABLE)

	
clear:
	clear
	rm -rf *.o $(EXECUTABLE)

clearall:
	rm -rf *.o $(EXECUTABLE) lib$(EXECUTABLE).a $(EXECUTABLE).so 
break:
	rm -rf *.o
index:
	make clearall
	git config --global user.email "lcpo.net@yandex.com"
	git config --global user.name  "S.S.Korotaev"
	git add -A
	git add *.c
	git add *.h
	git commit -a -m `date +%Y-%m-%d_%H:%M:%S`
	git push origin master

	
