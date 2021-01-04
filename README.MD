# HTWK Leipzig - 20INB-1 Grundladen der Programmierung Zwischenaufgabe

Author: Oliver Herrmann <oliver.herrmann@stud.htwk-leipzig.de>

## Aufgabe: Statistische Bewertung von Texten

In der Computerlinguistik, also der Vereinigung von Sprachwissenschaften mit Informatik, werden
Texte maschinell untersucht. In dem neuen Gebiet der "Digital Humanities" (digitale Geistes- wissenschaften)
wird der Computer als Unterstu ̈tzung gesehen, Texte zu anaysieren, ggf. sogar automatisch zu verstehen.
Wir fangen hier aber erst einmal bei einer einfachen Untersuchtung von Texten an: In dieser Aufgabe
geht es um die statistische Auswertung von Texten, indem wir die Wortha ̈ufigkeiten untersuchen.

Dazu sind texte in Form von txt-Dateien gegeben, die Sie im Ordner der Vorlesung finden. Schreiben
Sie ein Programm, das
- den Benutzer nach einer Datei fragt, sodass er den Pfad zu der Datei eingeben kann,
- za ̈hlt, wie viele Wo ̈rter in der Datei vorkommen
- za ̈hlt, wie Ha ̈ufig (absolute oder relative Ha ̈ufigkeit) die Wo ̈rter in der Datei vorkommen
- die Ergebnisse der Za ̈hlung in eine Datei schreibt. Hierfuür bietet sich das
Format: wort: häufigkeit wie im folgendne Beispiel an:

```
ist: 2000
soll: 100
Auto: 2
Buchweizencremesuppe: 20
Weihnachtsmann: 3
Slartibartfast: 40
```