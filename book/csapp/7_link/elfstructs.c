typedef struct {
    int   name;
    char  type:4,
          binding:4;
    char  reserved;
    short section;
    long  value;
    long  size;
} Elf64_Symbol;
