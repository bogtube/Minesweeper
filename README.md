# Minesweeper für's Terminal: 
Ein kommandozeilenbasiertes Minesweeper-Spiel in C++.
<img width="1026" height="376" alt="image" src="https://github.com/user-attachments/assets/7c481bfc-d974-4d6e-bac6-d2ec15415116" />

## Voraussetzungen
* Linux-Betriebssystem
* C++ Compiler (z. B. g++)
* CMake
* Make

## Installation und Start

1. **Quellcode herunterladen:**
   Laden Sie die Projektdateien von der Webseite herunter und entpacken Sie diese (alternativ über `git clone` klonen).

2. **In das Projektverzeichnis wechseln:**
   ```bash
   cd Pfad/zum/Minesweeper/Code

    Build-Verzeichnis erstellen und öffnen:
    Bash

    mkdir build && cd build

    Projekt konfigurieren:
    Bash

    cmake ..

    Kompilieren:
    Bash

    make

    Spiel ausführen:
    Bash

    ./minesweeper


Nach dem Start des Programms werden Sie gebeten, die Parameter für das Spielfeld (Höhe, Breite) sowie den Schwierigkeitsgrad (in Prozent) einzugeben.
Steuerung

Die Eingabe der Züge erfolgt über die Tastatur nach folgendem Format:
[Aktion] [X-Koordinate (Spalte)] [Y-Koordinate (Zeile)]

    Feld aufdecken (a): Beispiel: a 4 2 (deckt das Feld in Spalte 4, Zeile 2 auf)

    Flagge setzen / entfernen (f): Beispiel: f 5 5 (markiert das Feld in Spalte 5, Zeile 5 mit einer Flagge oder entfernt diese wieder)

Spielziel

Das Spiel ist gewonnen, wenn alle Felder, die keine Minen enthalten, aufgedeckt wurden. Das Spiel ist verloren, sobald ein Feld mit einer Mine aufgedeckt wird.
   

<img width="1013" height="543" alt="image" src="https://github.com/user-attachments/assets/c7da63fa-397d-4331-a1df-5a3db72fb680" />

