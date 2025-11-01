# Softwarelabor - Hochschule Karlsruhe

Dieses Repository enthält die Ergebnisse und Implementierungen aus dem Softwareprojekt-Labor an der Hochschule Karlsruhe.

## 📋 Übersicht

Das Repository ist in verschiedene Aufgaben (Assignments) unterteilt, die im Rahmen des Softwarelabors bearbeitet wurden. Jede Aufgabe behandelt unterschiedliche Konzepte der Softwareentwicklung und Programmierung.

## 📁 Projektstruktur

```
Softwarelabor/
├── Aufgabe 1/          # String-Manipulation in C
├── Aufgabe 2/          # Dynamische Arrays in C++
├── Aufgabe 3/          # Parser und AST für arithmetische Ausdrücke
├── Aufgabe 3b/         # Erweiterung mit Stack-basierter VM
├── Aufgabe3bb/         # Weitere VM-Implementierung
└── README.md           # Diese Datei
```

## 🔧 Aufgaben

### Aufgabe 1: String-Manipulation in C
**Sprache:** C  
**Dateien:** `main.c`, `main2.c`

Diese Aufgabe implementiert verschiedene String-Operationen in C, darunter:
- String-Normalisierung (Entfernung von Leerzeichen, Konvertierung zu Kleinbuchstaben)
- String-Längenberechnung
- String-Kopieren und Manipulation
- String-Umkehrung (Reverse)
- String-Vergleich
- String-Ersetzung

**Kompilierung:**
```bash
cd "Aufgabe 1"
gcc main.c -o main
./main
```

### Aufgabe 2: Dynamische Arrays in C++
**Sprache:** C++  
**Dateien:** `main.cpp`

Implementierung einer generischen dynamischen Array-Klasse (`DynArr`) mit Template-Unterstützung. Die Klasse bietet:
- Konstruktoren (Standard, Parametrisiert, Copy)
- Copy-Zuweisungsoperator
- Dynamische Speicherverwaltung
- Template-basierte Implementierung für verschiedene Datentypen

**Kompilierung:**
```bash
cd "Aufgabe 2"
g++ main.cpp -o main -std=c++11
./main
```

### Aufgabe 3: Parser für arithmetische Ausdrücke
**Sprache:** C++  
**Dateien:** `ast.cpp`, `ast.h`, `parser.cpp`, `parser.h`, `tokenizer.cpp`, `tokenizer.h`, `main.cpp`, `testParser.cpp`, `utility.h`

Diese Aufgabe implementiert einen vollständigen Parser für arithmetische Ausdrücke mit:
- **Tokenizer:** Lexikalische Analyse von Eingabestrings
- **Parser:** Top-Down-Parser für Ausdrücke (mit Grammatik für Addition und Multiplikation)
- **AST (Abstract Syntax Tree):** Baumrepräsentation von Ausdrücken
  - `IntExp`: Integer-Ausdrücke
  - `PlusExp`: Additions-Ausdrücke
  - `MultExp`: Multiplikations-Ausdrücke
- **Evaluator:** Berechnung des Ergebnisses
- **Pretty-Printer:** Ausgabe von Ausdrücken in lesbarer Form

**Grammatik:**
```
E  ::= T E'
E' ::= + T E' | ε
T  ::= F T'
T' ::= * F T' | ε
F  ::= N | (E)
```

**Kompilierung:**
```bash
cd "Aufgabe 3"
g++ ast.cpp parser.cpp tokenizer.cpp main.cpp -o main -std=c++11
./main

# Tests ausführen
g++ ast.cpp parser.cpp tokenizer.cpp testParser.cpp -o testParser -std=c++11
./testParser
```

### Aufgabe 3b: Stack-basierte Virtual Machine (VM)
**Sprache:** C++  
**Dateien:** `ast.cpp`, `ast.h`, `parser.cpp`, `parser.h`, `tokenizer.cpp`, `tokenizer.h`, `vm.cpp`, `vm.h`, `main.cpp`, `testVM.cpp`, `utility.h`

Erweiterung von Aufgabe 3 mit einer Stack-basierten Virtual Machine. Die VM unterstützt:
- **Opcodes:**
  - `PUSH i`: Legt einen Integer-Wert auf den Stack
  - `PLUS`: Addiert die obersten zwei Stack-Elemente
  - `MULT`: Multipliziert die obersten zwei Stack-Elemente
- **Stack-Operationen:** Ausführung von Bytecode-Instruktionen
- **Compiler:** Übersetzung von AST zu VM-Bytecode

Diese Implementierung demonstriert die Konzepte einer Stack-basierten Ausführungsumgebung ähnlich der Java Virtual Machine (JVM).

**Kompilierung:**
```bash
cd "Aufgabe 3b/gcc"
g++ ast.cpp parser.cpp tokenizer.cpp vm.cpp main.cpp -o main -std=c++11
./main

# VM-Tests ausführen
g++ ast.cpp parser.cpp tokenizer.cpp vm.cpp testVM.cpp -o testVM -std=c++11
./testVM
```

### Aufgabe 3bb: Erweiterte VM-Implementierung
**Sprache:** C++  
**Dateien:** Ähnlich wie Aufgabe 3b mit zusätzlichen Erweiterungen

Weitere Verfeinerung und Optimierung der Virtual Machine-Implementierung.

**Kompilierung:**
```bash
cd Aufgabe3bb
g++ ast.cpp parser.cpp tokenizer.cpp vm.cpp main.cpp -o main -std=c++11
./main
```

## 🛠️ Voraussetzungen

### Software-Anforderungen:
- **C-Compiler:** GCC (für Aufgabe 1)
- **C++-Compiler:** G++ mit C++11-Unterstützung oder höher (für Aufgaben 2, 3, 3b, 3bb)
- **Optional:** VS Code mit C/C++-Erweiterung (Konfigurationsdateien sind im Repository enthalten)

### Installation der Compiler (Ubuntu/Debian):
```bash
sudo apt-get update
sudo apt-get install build-essential
```

### Installation der Compiler (macOS):
```bash
xcode-select --install
```

### Installation der Compiler (Windows):
- MinGW oder MSYS2 für GCC/G++
- Alternativ: Visual Studio mit C++-Support

## 🚀 Verwendung

1. **Repository klonen:**
```bash
git clone https://github.com/yenesbas/Softwarelabor.git
cd Softwarelabor
```

2. **Gewünschte Aufgabe auswählen und kompilieren** (siehe spezifische Anweisungen oben)

3. **Programm ausführen:**
```bash
./main  # oder der entsprechende Name der ausführbaren Datei
```

## 📚 Konzepte und Lerninhalte

Dieses Labor behandelt folgende wichtige Konzepte der Informatik:
- **C-Programmierung:** Speicherverwaltung, Pointer, dynamische Allokation
- **C++-Programmierung:** Templates, OOP, Smart Pointers
- **Compiler-Bau:** Lexer/Tokenizer, Parser, AST
- **Virtuelle Maschinen:** Stack-basierte Ausführung, Bytecode
- **Datenstrukturen:** Stacks, Bäume, dynamische Arrays
- **Softwareentwicklung:** Modularisierung, Testing

## 👨‍💻 Autor

**Yenes Bas**  
Hochschule Karlsruhe - Technik und Wirtschaft  
Softwarelabor

## 📄 Lizenz

Dieses Projekt wurde im Rahmen des Studiums an der Hochschule Karlsruhe erstellt.

---

*Erstellt für das Softwarelabor an der Hochschule Karlsruhe*
