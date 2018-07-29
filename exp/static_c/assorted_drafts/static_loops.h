#define LOOP_TO_0(ID, N, BODY) {int ID; switch(N){\
case 7: ID=7;{BODY};\
case 6: ID=6;{BODY};\
case 5: ID=5;{BODY};\
case 4: ID=4;{BODY};\
case 3: ID=3;{BODY};\
case 2: ID=2;{BODY};\
case 1: ID=1;{BODY};\
case 0: ID=0;{BODY};\
}}

#define LOOP_TO(ID, START, END, BODY) \
  LOOP_TO_0(ID, (END)-(START), ID=(END)-ID; BODY)

#define LOOP_DOWNTO(ID, START, END, BODY) \
  LOOP_TO_0(ID, (START)-(END), ID=(END)+ID; BODY)

