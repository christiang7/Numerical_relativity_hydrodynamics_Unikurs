Content-Type: text/x-zim-wiki
Wiki-Format: zim 0.6
====== Numerische_Lösung_von_Differentialgleichungen_-_Das_Runge-Kutta_Verfahren.pdf ======
Text date: [[Zettelkasten:2025:01:25|2025-01-25]] Modi date: [[Zettelkasten:2023:11:26|2023-11-26]]
@ARTIKEL  
**[[./Numerische_Lösung_von_Differentialgleichungen_-_Das_Runge-Kutta_Verfahren.pdf]] **



{{./Numerische_Lösung_von_Differentialgleichungen_-_Das_Runge-Kutta_Verfahren.pdf.avif?width=500}}

Pages:           12


Numerische Lösung von Differentialgleichungen
Das Runge-Kutta Verfahren
Bei weitem nicht jede Differentialgleichung lässt sich analytisch lösen. Und selbst wenn, ist eine solche
Lösung nur mit viel Erfahrung und Aufwand zu erreichen. Mit numerischen Methoden kann man
grundsätzlich jede Differentialgleichung lösen.
Differentialgleichung treten immer dann auf, wenn es um zeitabhängige Vorgänge, z.B. Wärme- und
Stofftransportvorgänge wie Temperaturverteilung in Körpern, Diffusion und chemische Reaktionen geht.
Die grundsätzliche Form einer Differentialgleichung lautet:

y 

dy
 f ( x, y )
dx

Bekanntlich ist das Lösen von Differentialgleichung nur in einfachen Fällen analytisch lösbar, z.B. durch
Trennung der Variablen und Integration beider Seiten. In Fällen, wo eine solche Lösung nicht möglich bzw.
nicht bekannt ist, steht als Alternative die numerische Lösung der Differentialgleichung zur Verfügung. Diese
funktioniert nach folgendem Prinzip.
Die Differentialgleichung

y 

dy
 f ( x, y )
dx

wird als Differenzengleichung umgeschrieben und schrittweise gelöst.

y 

y
 f ( x, y )
x

y  f ( x, y)x

y  yi 1  yi
Aus den GrenzenxA = x Anfang und xE = x Ende setzt man xi=xA. yi muß an der Stelle xi bekannt sein. Mit
einem möglichst kleinen Δx berechnet man dann aus der Funktion f(xi,yi) das neue yi+1.
Der Vorgang wird solange wiederholt, bis xi=xE ist. In der Literatur (z.B. www.mathematik.ch,
Differentialgleichungen.dpf) wird das Verfahren unter dem Namen Euler detailliert beschrieben. Der
Näherungsfehler ist dabei proportional der Schrittweite h=Δx., d.h. man muß eine sehr kleine Schrittweote
wählen, was die Rechenzeit verlängert.
Die Runge-Kutta-Methode hat einen Näherungsfehler von h4 und ist damit erheblich genauer als die Euler
Methode und für die praktische Anwendung eines der am häufigsten verwendeten Methoden. Wir
-1-

