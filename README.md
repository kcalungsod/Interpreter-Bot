A conversational AI chatbot developed in C++ that translates Filipino and Chinese words and phrases into English.

Interpreter Bot has three main functions. These are: (1) to translate English words or phrases to Filipino; (2) to translate English words or phrases to Chinese Mandarin; (3) to continuously expand its database and “learn” new words and sentences. It does all of this while providing a conversational platform – engaging the users to take part and interact with the IBot while learning new languages.

The loop for English to Filipino and English to Chinese function, runs similarly – with their databases as their only difference. Both databases contain the same number of words with their own respective English translations. The system first converts the user’s input into lower case string for uniformity, searched through the database through sequential search, and finally output a response once a match is found. If there’s none, a learning function is also included with users providing their own translations on the English words they’ve entered.

It should be noted however that for the learning function, the system automatically tags user-input addition to the database as “under validation”. This was done in order to uphold the integrity of the database. With this tag, other users who would use the application, will know that they should take translations appended with “(under validation)”, with a grain of salt and use other resources to verify before the additional phrases or words passes the review done by the developers.

There are enough error checks in place in every input the user enters. The system checks if they’re entering within the acceptable list of characters, if the user is not entering any input, and if the answer isn’t within the choices provided by IBot. Furthermore, the group has also included shortcuts for greater accessibility – with the system accepting “Y” and “y” and “N” or “n” for a yes or no questions  or “f” or “F” for Filipino and “c” or “C” in the prompt asking what language they want to translate their previous user input messages into. 

All conversations start and end with English, with the bot only terminating or saying goodbye once the user reply with “x” or “X” in any of the prompt given to user.
