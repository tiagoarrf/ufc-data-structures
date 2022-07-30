# gnuplot file
# generates the graph for all list algoritms sort
# by Tiago A. Fontenele - 387300
# date: 03/04/2021

set term png                                                   # will produce .png output
set output "graficos/com_listas/list_todos.png"                # output to any filename.png you want
set grid                                                       # grid background
set title 'Com Lista Duplamente Encadeada'                                    # plot title
set xlabel 'Tamanho da Lista'                                  # x-axis label
set ylabel 'Microssegundos'                                    # y-axis label
set key left top                                               # legend left
set multiplot                                                  # multiplot mode (prompt changes to 'multiplot')

# plot the graphic
plot 'resultados/list_insertion.txt' with linespoints title 'Insertion', 'resultados/list_selection.txt' with linespoints title 'Selection', 'resultados/list_merge.txt' with linespoints title 'Merge', 'resultados/list_quick.txt' with linespoints title 'Quick', 'resultados/list_shell.txt' with linespoints title 'Shell'



unset multiplot                     # exit multiplot mode (prompt changes back to 'gnuplot')
