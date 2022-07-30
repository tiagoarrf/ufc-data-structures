# gnuplot file
# gerando gráfico para o shell sort
# by Tiago A. Fontnele - 387300
# date: 03/04/2021

set term png                                            # will produce .png output
set output "graficos/com_listas/list_shell.png"              # output to any filename.png you want
set grid                                                # grid background
set title 'Desempenho Shell Sort'                       # plot title
set xlabel 'Tamanho da Lista'                           # x-axis label
set ylabel 'Microsegundos'                              # y-axis label
set nokey                                               # no legend

# plot the graphic
plot 'resultados/list_shell.txt' with linespoints title 'Shell Sort'