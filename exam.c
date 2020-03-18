// Midterm exam – The C Programming Language, Spring 2020
// (Coding section – 52 points)
// POST ALL of this CODE to your ______.github.io portfolio.
// (8 pts) (1) Find any and all mistakes in the following code, and correct them.
void count() {
 printf("Enter lines of text here: .../n");
 int c, nc = 0, nt = 0, nbackslash = 0, nl = 0;
 while ((c = fgetc(stdin)) != EOF) {
 if (c == '\n') { ++nl;
 } else if (c == '\t') { ++nt;
 } else if (c == '\\') { ++nbackslash;
 } else if (isspace(c)) { ++nc; }
 printf("lines: %d\n", nl);
 printf("tabs: %d\n", nt);
 printf("backslashes: %d\n", nbackslash);
 printf("alphanumeric: %d\n", nc);
}
}
int main(int argc, const char* argv[]) {
 count();
 return 0;
}
// The C Standard Library: Identify the standard library functions that do the following…
// (3 pts) (2) Find the first character c in a const char* s: ________char* strchr(const char* s, char c);____________
// (3 pts) (3) Find the length of the prefix of const char* s that has characters in const char* t: __________size_t strspn(const char* s, const char* t);_______
// (3 pts) (4) Terminate a program immediately _______________exit();_______________
// (3 pts) (5) Open the file “midterm.txt” in read mode ____________fopen("midterm.txt","r");_______________
// Using pointers, implement each of the following C standard library functions
size_t strcpy(char* s, const char* t){
    char* p = s;
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
    return p;
} // (4 pts) (6)
char* strncat(char* s, const char* t, size_t n){
    char* p = s;
    while(*s++ != '\0'){};
    while((n-- != 0 && *t != '\0')){
        *s++ = *t++;
    }
    *s++ = '\0';
    return p;
} // (4 pts) (7)
int strcmp(const char* s, const char* t){
    while(*s != '\0' && *t != '\0' && *t == *s){
        ++s;
        ++t;
    }
    return s - t;
} // (4 pts) (8)
// PART III: SHORT PROGRAM
(20 pts) (9) Fill in the program code below for the square ADT (abstract data type)
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };
square* square_init(double ulx, double uly, double side){
    square *sq = (square*)malloc(sizeof(square));
    sq->ul.x = ulx;
    sq->ul.y = uly;
    sq->side = side;
} // TODO
void square_delete(square* sq){
    free(sq);
} // TODO
void square_move(square* sq, double x, double y){
    sq -> ul.x = x;
    sq -> ul.y = y;
} // TODO
void square_expandby(square* sq, double expandby){
    sq ->ul.x -= expandby;
    sq ->ul.y += expandby;
    sq ->side = side + (expandby * 2);
} // TODO
double square_area(square* sq){
    double area = r ->side * r->side;
    return area;
} // TODO



double square_perimeter(square* r){
    return r -> side *4;
} // TODO
// print location, side, area and perimeter
void square_print(const char* msg, square* sq){
    printf("%s upper left is (%f,%f), side = %f", msg, r->ul.x,r->ul.y,r->side);
} // TODO
void test_square(double ulx, double uly, double side) {
 square* sq = square_init(ulx, uly, side);
 square_print(“sq is: “, sq);
 square_move(2, 2);
 square_print(“sq is now: “, sq);
 square_expandby(sq, 10);
 square_print(“sq has expanded to: “, sq);
 square_delete(sq);
 printf(“\n\n”);
}
void tests_square() {
 test_square(0, 0, 10);
 test_square(1, 1, 5);
 // add other tests if you wish // TODO (optional)
}
int main(int argc, const char* argv[]) {
 tests_square();
 return 0;
}
