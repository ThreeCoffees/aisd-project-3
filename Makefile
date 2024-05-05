FLAGS += -ggdb3
SRCS := $(shell find . -name '*.cpp')
HEADERS := $(shell find . -name '*.h')

OUTPUT := app

all: $(OUTPUT)

$(OUTPUT): $(SRCS) $(HEADERS)
	g++ $(FLAGS) $(SRCS) -o $(OUTPUT)

clean:
	rm *.o app

