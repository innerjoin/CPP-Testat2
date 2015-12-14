# CPP-Testat2
My personal solution for the second 'Testat' @ HSR Hochschule für Technik Rapperswil. There is still room for some improvement, but that this solution can be considered save to pass the review.

# Reqirements
From Parnas [ Parnas72 ] we have a concise definition of the Keyword in Context problem:

> The KWIC index system accepts an ordered set of lines, each line is an ordered set of words, and each word is an ordered set of characters. Any line may be "circularly shifted" by repeatedly removing the first word and appending it at the end of the line. The KWIC index system outputs a listing of all circular shifts of all lines in alphabetical order. 

Write a program kwic that reads lines from standard input and creates the variations of the line where each word is in front once. Output the stored lines in sorted order, so that you can see, how the words are used in context.

Example input:
> this is a test <br>
> this is another test

result:
> a test this is <br>
> another test this is <br>
> is a test this <br>
> is another test this <br>
> test this is a <br>
> test this is another <br>
> this is a test <br>
> this is another test <br>

### Tipps:

  - use algorithms rotate or rotate_copy to generate the word lists for each line.
  - You must use your word class from ExW6 to be able to ignore punctuation and case of the letters.
  - Use the appropriate data structures to achieve the result without unnecessary code or loops.
  - In addition to the test of your word class you can also separate your logic into independently testable functions, provide the tests and your main() function. 
