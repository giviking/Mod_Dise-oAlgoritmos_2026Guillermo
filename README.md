<div align="center">

# 📘 Portafolio de Evidencias

### Nombre Completo de la Persona Estudiante

**CSTI12010 · Diseño de algoritmos** · Instituto Nacional de Aprendizaje

Facilitador: Giovanni Antonio Coto Calderón · Grupo _(número)_ · 2026

![PSeInt](https://img.shields.io/badge/PSeInt-Estricto-2E7D32)
![C](https://img.shields.io/badge/C-C11-A8B9CC?logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-MSYS2-A42E2B?logo=gnu&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?logo=git&logoColor=white)
![GitHub](https://img.shields.io/badge/GitHub-181717?logo=github&logoColor=white)

</div>

---

## 📖 Sobre este portafolio

Este repositorio reúne el trabajo que realizo en el módulo **Diseño de algoritmos**:
primero los algoritmos en **PSeInt** (UA1) y después su traducción y desarrollo en
**lenguaje C** (UA2 y UA3). Cada sesión tiene su carpeta con los archivos de trabajo y
un `README.md` con la prueba de ejecución, lo que aprendí y mi autoevaluación.

> **Recorrido sugerido:** revisar la bitácora para ver el trabajo más reciente, luego el
> registro de evidencias por unidad y abrir el enlace de las sesiones que interesen.

**Estado de cada sesión:** ⬜ Pendiente · 🟡 En proceso · ✅ Completa

---

## 🗓 Bitácora diaria

Una fila por día de clase, **la más reciente arriba**. Se completa al final de la jornada,
antes del último `git push`.

| Fecha | Sesión | Qué hice hoy                                       | Pendiente para la próxima   |
| :---: | :----: | :------------------------------------------------- | :-------------------------- |
| dd/mm |  S18   | _(ej.: traduje Aprobacion y CajeroAutomatico a C)_ | _(ej.: terminar credito.c)_ |
| dd/mm |  S17   |                                                    |                             |

<details>
<summary><b>Rutina de cada día</b></summary>

```bash
git pull                                   # 1. traer lo más reciente
# 2. trabajar en la carpeta de la sesión (UA2/S18/...) y completar su README.md
git status                                 # 3. revisar qué cambió
git add .                                  # 4. preparar los cambios
git commit -m "S18: agrega credito.c"      # 5. registrar con el formato SXX: verbo + qué
git push                                   # 6. subir a GitHub
```

Antes del último `push` del día: agregar la fila de la bitácora y actualizar el estado
de la sesión en el registro de evidencias.

</details>

---

## 📁 Estructura del repositorio

```
CSTI12010-2026-nombre-apellido/
├── README.md                ← este archivo (presentación, bitácora y registro)
├── UA1/S01 … S12/           ← algoritmos en PSeInt (.psc), una carpeta por sesión
├── UA2/S14 … S22/           ← programas en C (.c), una carpeta por sesión
├── UA3/                     ← estructuras de datos
├── actividades/             ← actividades de comprobación A1, A2 y A3
└── docs/
    ├── CONVENCIONES.md      ← nombres, commits, ramas y entregas
    └── PLANTILLA_SESION.md  ← modelo del README de cada sesión
```

Las capturas de pantalla van en la subcarpeta `capturas/` de cada sesión
(por ejemplo `UA2/S17/capturas/factura.png`).

---

## 📋 Registro de evidencias

<details>
<summary><b>Unidad 1 · Elaboración de algoritmos en PSeInt</b> (sesiones 1 a 13)</summary>

| Sesión | Tema                                              | Qué aprendí                            |                Evidencia                 | Estado |
| :----: | :------------------------------------------------ | :------------------------------------- | :--------------------------------------: | :----: |
|  S01   | Lógica computacional, compilador e intérprete     | _(escribir aquí con palabras propias)_ |             [ver](UA1/S01/)              |   ⬜   |
|  S02   | Algoritmos y pseudocódigo                         |                                        |             [ver](UA1/S02/)              |   ⬜   |
|  S03   | Lenguajes de alto y bajo nivel                    |                                        |             [ver](UA1/S03/)              |   ⬜   |
|  S04   | Metodología de solución de problemas              |                                        |             [ver](UA1/S04/)              |   ⬜   |
|  S05   | Entrada, proceso, salida y tipos de datos         |                                        |             [ver](UA1/S05/)              |   ⬜   |
|  S06   | Constantes, variables y expresiones               |                                        |             [ver](UA1/S06/)              |   ⬜   |
|  S07   | Contadores y acumuladores                         |                                        |             [ver](UA1/S07/)              |   ⬜   |
|  S08   | Expresiones aritméticas, relacionales y lógicas   |                                        |             [ver](UA1/S08/)              |   ⬜   |
|  S09   | Operadores aritméticos y prioridad                |                                        |             [ver](UA1/S09/)              |   ⬜   |
|  S10   | Decisión simple y doble                           |                                        |             [ver](UA1/S10/)              |   ⬜   |
|  S11   | Operadores lógicos, decisiones compuestas y Según |                                        |             [ver](UA1/S11/)              |   ⬜   |
|  S12   | Ciclos, validación de datos e informe             |                                        |             [ver](UA1/S12/)              |   ⬜   |
|  S13   | **Actividad de comprobación 1**                   |                                        | [ver](actividades/A1_Analisis_problema/) |   ⬜   |

</details>

<details open>
<summary><b>Unidad 2 · Programación estructurada en C</b> (sesiones 14 a 24)</summary>

| Sesión  | Tema                                         | Qué aprendí |                  Evidencia                   | Estado |
| :-----: | :------------------------------------------- | :---------- | :------------------------------------------: | :----: |
|   S14   | Sistemas numéricos                           |             |               [ver](UA2/S14/)                |   ⬜   |
|   S15   | Control de versiones con git y GitHub        |             |               [ver](UA2/S15/)                |   ⬜   |
|   S16   | Formato de un programa en C y compilación    |             |               [ver](UA2/S16/)                |   ⬜   |
|   S17   | Variables, constantes y entrada/salida       |             |               [ver](UA2/S17/)                |   ⬜   |
|   S18   | Operadores, casting e if … else              |             |               [ver](UA2/S18/)                |   ⬜   |
|   S19   | Ciclos y switch                              |             |               [ver](UA2/S19/)                |   ⬜   |
|   S20   | Arreglos, matrices y cadenas                 |             |               [ver](UA2/S20/)                |   ⬜   |
|   S21   | Funciones                                    |             |               [ver](UA2/S21/)                |   ⬜   |
|   S22   | Paso de parámetros por valor y por dirección |             |               [ver](UA2/S22/)                |   ⬜   |
| S23–S24 | **Actividad de comprobación 2**              |             | [ver](actividades/A2_Mi_primera_aplicacion/) |   ⬜   |

</details>

<details>
<summary><b>Unidad 3 · Estructuras de datos</b></summary>

| Sesión | Tema                                       | Qué aprendí | Evidencia | Estado |
| :----: | :----------------------------------------- | :---------- | :-------: | :----: |
|        | _(las filas se agregan al iniciar la UA3)_ |             |           |        |

</details>

---

## 🏁 Actividades de comprobación

| Actividad                                          | Carpeta                                       | Versión evaluada (etiqueta) | Resultado |
| :------------------------------------------------- | :-------------------------------------------- | :-------------------------: | :-------: |
| A1 · Análisis y solución de un problema específico | [ver](actividades/A1_Analisis_problema/)      |              —              |           |
| A2 · Mi primera aplicación                         | [ver](actividades/A2_Mi_primera_aplicacion/)  |     `A2-oportunidad-1`      |           |
| A3 · Sistema con almacenamiento de datos           | [ver](actividades/A3_Sistema_almacenamiento/) |     `A3-oportunidad-1`      |           |

La persona facilitadora crea la etiqueta al cierre de cada actividad; el resultado se anota
cuando se comunica.

---

## 🖼 Galería de ejecuciones

_(Sustituir por capturas propias. Se recomienda incluir de tres a seis imágenes
representativas: un algoritmo en PSeInt y varios programas en C funcionando.)_

<p align="center">
  <img src="UA2/S18/capturas/credito.png" width="600" alt="Ejecución de credito.c en la terminal de VS Code">
</p>

<div align="center"><i>credito.c (sesión 18): decisión con &&, || y ! en C.</i></div>

### El mismo algoritmo en dos lenguajes

|                                    PSeInt (UA1)                                    |                                     C (UA2)                                     |
| :--------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------: |
| <img src="UA1/S10/capturas/aprobacion.png" width="320" alt="Aprobacion en PSeInt"> | <img src="UA2/S18/capturas/aprobacion.png" width="320" alt="aprobacion.c en C"> |

---

## 🧠 Decisiones de diseño documentadas

_(Completar conforme avanza el módulo. Ejemplos de lo que corresponde anotar aquí.)_

| Decisión                                    | Qué elegí | Por qué |
| :------------------------------------------ | :-------- | :------ |
| Tipo de dato para montos de dinero          |           |         |
| Cómo valido los datos de entrada            |           |         |
| Cuándo uso `if … else if` y cuándo `switch` |           |         |
| Cuándo divido el programa en funciones      |           |         |

---

## 💭 Reflexión por unidad

| Unidad | Lo más importante que aprendí | Lo que más me costó y cómo lo superé |
| :----: | :---------------------------- | :----------------------------------- |
|  UA1   |                               |                                      |
|  UA2   |                               |                                      |
|  UA3   |                               |                                      |

**Reflexión final** _(escribir al cerrar el módulo; tres preguntas para orientarla):_

1. ¿Qué sé hacer hoy que no sabía el primer día?
2. Comparando un algoritmo en PSeInt con el mismo programa en C: ¿qué cambió en la
   forma de escribirlo y qué se mantuvo igual en la lógica?
3. ¿Qué me propongo seguir aprendiendo por mi cuenta?

---

## 🛠 Herramientas empleadas

- **Pseudocódigo y diagramas:** PSeInt con el perfil Estricto
- **Lenguaje:** C (estándar C11)
- **Compilador:** gcc de MSYS2 (UCRT64), compilando con `gcc -Wall`
- **Editor:** Visual Studio Code con la extensión C/C++
- **Terminal:** Git Bash
- **Control de versiones:** Git y GitHub

---

<div align="center">

**Nombre Completo** · @usuario-de-github

Portafolio elaborado durante el módulo CSTI12010 · Instituto Nacional de Aprendizaje · 2026

_Repositorio privado. Todo el contenido es de mi autoría; cuando uso material de otra fuente, la cito._

</div>
