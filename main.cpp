#include <iostream>

using namespace std;

double saisi(){
    double n;
    cout << "Entrer la note : ";
    cin >> n;
    while((n < 0 || n > 100) && n != -1){
        cout << "Invalid, recommencer : ";
        cin >> n;
    }
    return n;
}

double moyenne_note(double sum_note, int number_note){
    if(number_note == 0){
        return 0.0;
    }else{
        return sum_note / number_note;
    }
}

int main()
{
    double note;
    double min_note;
    double max_note;
    double sum_note = 0;
    double number_note = 0;
    int again = 0;

    do{
        cout << "--- Bienvenu au programme de saisi de note ----" << endl;
        note = saisi();
        if(note == -1){
            min_note = 0;
            max_note = 0;
        }else{
            min_note = note;
            max_note = note;
            number_note += 1;
            sum_note += note;
        }

        while(note != -1){
            note = saisi();
            if(note == -1) break;
            // traitement min
            if(note < min_note){
                min_note = note;
            }
            // traitement num
            if(note > max_note){
                max_note = note;
            }
            // sum and count note
            sum_note += note;
            number_note += 1;
        }
        cout << " ------- RESULTAT -----------" << endl;
        cout << "MINIMUM : " << min_note << endl;
        cout << "MAXMUM : " << max_note << endl;
        cout << "MOYENNE : " << moyenne_note(sum_note, number_note) << endl << endl;
        cout << "Voulez-vous reessayer ? Non (0) / Oui (1) : ";
        cin >> again;
    }while(again == 1);
    cout << "Bye!" << endl;
    return 0;
}
