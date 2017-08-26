// equivalent value of EOF is -1

/* printing valie of EOF :

 void main()
 {
 printf("%d" , EOF);
}

// feof function is used to detect the end of file 
 
 int can be used in text ifle 
 
 feof returns TRUE if end of file is reached !!!! 
 
 Syntax :
 int  feof ( FILE *fp );
 
 ways of writing feof function:
  way 1 :
  if ( feof(fptr) == 1 ) // as if (1) is TRUE
  printf("End of file");
  
  way2 :
  while (!feof(fptr))
  {
  --------
  ------
}

