## Ο Αλγόριθμος

Αρχικά, στον κώδικά μας βρίσκονται οι **βιβλιοθήκες**, οι **αρχικοποιήσεις** των μεταβλητών και οι **ονοματοδοσίες** των pins του Arduino.
Εκεί, βρίσκεται και ο κώδικας για τη σύνδεση με το **Wi-Fi**, στον οποίο πρέπει να ορίσουμε το όνομα του δικτύου μας και τον κωδικό του.

Στη μέθοδο ***setup()*** ορίζουμε αν το κάθε pin του Arduino χρησιμοποιείται ως **είσοδος ή ως έξοδος**.
Επίσης, δηλώνουμε σε ποια συχνότητα θα γίνεται η **σειριακή επικοινωνία** του Arduino με τον υπολογιστή μας, μέσω του USB, για όταν κάνουμε τις δοκιμές μας και θέλουμε να εκτυπώσουμε κάτι στο σειριακό παράθυρο.

Το βασικό τμήμα του αλγορίθμου μας βρίσκεται στη μέθοδο ***loop()***.

Εκεί, αρχικά μετράμε την τιμή που μας επιστρέφει ο **αισθητήρας θερμοκρασίας** και στη συνέχεια με τον τύπο *τιμή αισθητήρα θερμοκρασίας * (5/1024)* μετατρέπουμε αυτή την τιμή σε **volts**. Έπειτα, μετατρέπουμε τα volts σε **βαθμούς Κελσίου** με τον τύπο *volts * 50*.

Στη συνέχεια, μετράμε την τιμή που μας επιστρέφει ο **αισθητήρας καπνού**.

Συνεπώς, είμαστε έτοιμοι τώρα να κάνουμε τον **έλεγχό** μας με την if που ακολουθεί και έτσι αν υπάρχει **πολύς καπνός** και **πολύ υψηλή θερμοκρασία**, να ηχήσει το **buzzer** σαν συναγερμός για να ειδοποιήσει τους ανθρώπους και τα ζώα. Όπως μπορείτε να παρατηρήσετε, το buzzer μας ηχεί μόνο 3 φορές. Αυτό το κάναμε για να μην ήταν κουραστικό στη φάση δοκιμής. Κανονικά θα έπρεπε ο συναγερμός να ηχεί πιο πολλές φορές και για περισσότερη ώρα (ίσως με την προσθήκη μίας for).

Τέλος, θέλουμε να γνωρίζουμε την **τάση φόρτισης** της **μπαταρίας**, για να ξέρουμε πόσο **φορτισμένη** είναι η συσκευή μας. Γνωρίζουμε πως, η αναλογική είσοδος δέχεται από 0-5V χρησιμοποιώντας τις τιμές από 0-1023 αντίστοιχα. Για τον λόγο αυτόν χρησιμοποιήθηκε ως μετατροπέας AD (αναλογικού σήματος σε ψηφιακό) - ο δικής μας κατασκευής - διαιρέτης τάσης, ο οποίος εφαρμόζεται στην μπαταρία των 12V του project και σε πλήρη φόρτιση στέλνει στην αναλογική είσοδο 5V.

Έτσι, για τον υπολογισμό της τάσης φόρτισης της μπαταρίας χρησιμοποιούμε τον τύπο *(τιμή αναλογικής μέτρησης * 12)/1023* προκειμένου να μετατρέψουμε αντίστροφα την τιμή της αναλογικής μέτρησης (0-1023) σε volt (0-12).
