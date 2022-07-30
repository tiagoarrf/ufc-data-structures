# gnuplot file
# gerando gráfico para o insertion sort
# by Tiago A. Fontnele - 387300
# date: 03/04/2021

set term png                                            # will produce .png output
set output "graficos/com_vetores/vet_insertion.png"         # output to any filename.png you want
set grid                                                # grid background
set title 'Desempenho Insertion Sort'                   # plot title
set xlabel 'Tamanho do Vetor'                           # x-axis label
set ylabel 'Microsegundos'                              # y-axis label
set nokey                                               # no legend

# plot the graphic
plot 'resultados/vet_insertion.txt' with linespoints title 'Insertion Sort'