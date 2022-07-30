# gnuplot file
# generates the graph for all array algoritms sort
# by Tiago A. Fontenele - 387300
# date: 03/04/2021

set term png                                                   # will produce .png output
set output "graficos/com_vetores/vet_todos.png"                # output to any filename.png you want
set grid                                                       # grid background
set title 'Com Vetor Simples'                                    # plot title
set xlabel 'Tamanho do Vetor'                                  # x-axis label
set ylabel 'Microssegundos'                                    # y-axis label
set key left top                                               # legend left
set multiplot                                                  # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot 'resultados/vet_insertion.txt' with linespoints title 'Insertion', 'resultados/vet_selection.txt' with linespoints title 'Selection', 'resultados/vet_merge.txt' with linespoints title 'Merge', 'resultados/vet_quick.txt' with linespoints title 'Quick', 'resultados/vet_shell.txt' with linespoints title 'Shell'



unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')
