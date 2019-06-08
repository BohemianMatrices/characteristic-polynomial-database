def get_properties(property_file = 'Properties.csv'):
    
    properties_dict = dict()
    index_to_property_map = list()

    # Min/Max matrix dimension
    n_min = 10000
    n_max = 0

    with open(property_file, 'r') as f:
    
        # Process header
        header_line = next(f)
        header_line = header_line.rstrip('\n')
        header_line = header_line.split(',')
    
        for i in range(len(header_line)):
            properties_dict[header_line[i]] = dict()
            index_to_property_map.append(header_line[i])
    
        # Process OEIS
        oeis_line = next(f)
        oeis_line = oeis_line.rstrip('\n')
        oeis_line = oeis_line.split(',')
    
        for i in range(len(oeis_line)):
            k = index_to_property_map[i]
            properties_dict[k]['oeis'] = oeis_line[i]
    
        # Process data
        for line in f:
            line = line.rstrip('\n')
            line = line.split(',')
            n_min = min(int(line[0]), n_min)
            n_max = max(int(line[0]), n_max)
        
            for i in range(len(line)):
                k = index_to_property_map[i]
                key_name = line[0]
                properties_dict[k][key_name] = line[i]
    
    return (properties_dict, n_min, n_max)


def write_section(f, properties_dict, header_name, subproperties, n_min, n_max):

    # Header
    f.write('### {}\n\n'.format(header_name))

    # Table header
    f.write('| Matrix Size |')
    for s in subproperties:
        f.write(' {} |'.format(s))
    f.write('\n')

    # Table separator
    f.write('| --- |')
    for s in subproperties:
        f.write(' --- |')
    f.write('\n')

    # OEIS line
    f.write('| [__OEIS__](https://oeis.org/) |')
    for s in subproperties:
        if properties_dict[s]['oeis'] != '':
            f.write(' [__{0}__](https://oeis.org/{0})'.format(properties_dict[s]['oeis']))
        f.write(' |')
    f.write('\n')

    # Property values
    for i in range(n_min, n_max+1):
        f.write('| {0}x{0} |'.format(i))

        for s in subproperties:
            if properties_dict[s][str(i)] == '':
                f.write(' |')
            else:
                f.write(' {:,} |'.format(int(properties_dict[s][str(i)])))
        f.write('\n')
    f.write('\n')


def write_readme(title,
                 population_title,
                 property_file = 'Properties.csv',
                 readme_file = 'README2.md'):
    
    # Load properties from file
    (properties_dict, n_min, n_max) = get_properties(property_file = property_file)
    
    with open(readme_file, 'w') as f:
        
        # Title
        f.write('# {}\n\n'.format(title))
        
        # Population
        f.write('{}\n\n'.format(population_title))
        
        # Properties header
        f.write('## Properties\n\n')
        f.write('The [Properties.csv](Properties.csv) file contains all the properties in the tables below.\n\n')
        
        # ------------------------------------------------------------------------ #
        # Characteristic Polynomials                                               #
        # ------------------------------------------------------------------------ #
        header_name = 'Characteristic Polynomials'
        subproperties = ['Number of Matrices',
                         'Number of Characteristic Polynomials',
                         'Number of Minimal Polynomials',
                         'Number of Non-Derogatory Matrices',
                         'Maximum Characteristic Height']
        write_section(f, properties_dict, header_name, subproperties, n_min, n_max)
        
        # ------------------------------------------------------------------------ #
        # Eigenvalues                                                              #
        # ------------------------------------------------------------------------ #
        header_name = 'Eigenvalues'
        subproperties = ['Number of Distinct Eigenvalues',
                         'Number of Distinct Real Eigenvalues',
                         'Number of Distinct Purely Complex Eigenvalues',
                         'Number of Distinct Jordan Canonical Forms']
        write_section(f, properties_dict, header_name, subproperties, n_min, n_max)
    
        # ------------------------------------------------------------------------ #
        # Rank                                                                     #
        # ------------------------------------------------------------------------ #
        header_name = 'Rank'
        subproperties = ['Number of Singular Matrices',
                         'Number of Non-Singular Matrices']
        for i in range(1, n_max+1):
            subproperties.append('Number of Rank {} Matrices'.format(i))
        write_section(f, properties_dict, header_name, subproperties, n_min, n_max)
    
        # ------------------------------------------------------------------------ #
        # Determinant                                                              #
        # ------------------------------------------------------------------------ #
        header_name = 'Determinant'
        subproperties = ['Number of Distinct Determinants',
                         'Maximum Determinant',
                         'Number of Unimodular Matrices']
        write_section(f, properties_dict, header_name, subproperties, n_min, n_max)
        
        # ------------------------------------------------------------------------ #
        # Miscellaneous                                                            #
        # ------------------------------------------------------------------------ #
        header_name = 'Miscellaneous'
        subproperties = ['Number of Normal Matrices',
                         'Number of Rhapsodic Matrices',
                         'Number of Nilpotent Matrices',
                         'Number of Totally Unimodular Matrices',
                         'Number of Type I Stable Matrices',
                         'Number of Type II Stable Matrices']
        write_section(f, properties_dict, header_name, subproperties, n_min, n_max)



if __name__ == '__main__':
    
    import glob
    import os
    
    property_files_list = []
    
    # Unstructured
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_1/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_1/README.md',
                                'title': 'Unstructured_0_1',
                                'population_title': 'Matrices with entries from the set {0, +1}.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_1_2/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_1_2/README.md',
                                'title': 'Unstructured_0_1_2',
                                'population_title': 'Matrices with entries from the set {0, +1, +2}.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_Diag_0_1/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_Diag_0_1/README.md',
                                'title': 'Unstructured_0_Diag_0_1',
                                'population_title': 'Matrices with entries from the set {0, +1} and diagonal entries fixed at 0.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_Diag_0_1_2/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_Diag_0_1_2/README.md',
                                'title': 'Unstructured_0_Diag_0_1_2',
                                'population_title': 'Matrices with entries from the set {0, +1, +2} and diagonal entries fixed at 0.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_Diag_n1_0/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_Diag_n1_0/README.md',
                                'title': 'Unstructured_0_Diag_n1_0',
                                'population_title': 'Matrices with entries from the set {-1, 0} and diagonal entries fixed at 0.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_Diag_n1_0_1/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_Diag_n1_0_1/README.md',
                                'title': 'Unstructured_0_Diag_n1_0_1',
                                'population_title': 'Matrices with entries from the set {-1, 0, +1} and diagonal entries fixed at 0.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_0_Diag_n1_1/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_0_Diag_n1_1/README.md',
                                'title': 'Unstructured_0_Diag_n1_1',
                                'population_title': 'Matrices with entries from the set {-1, +1} and diagonal entries fixed at 0.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_n1_0/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_n1_0/README.md',
                                'title': 'Unstructured_n1_0',
                                'population_title': 'Matrices with entries from the set {-1, 0}.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_n1_0_1/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_n1_0_1/README.md',
                                'title': 'Unstructured_n1_0_1',
                                'population_title': 'Matrices with entries from the set {-1, 0, +1}.'})
    property_files_list.append({'property_file': 'Unstructured/Unstructured_n1_1/Properties.csv',
                                'readme_file': 'Unstructured/Unstructured_n1_1/README.md',
                                'title': 'Unstructured_n1_1',
                                'population_title': 'Matrices with entries from the set {-1, +1}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_1/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_1/README.md',
                                'title': 'UH_1_Subdiag_0_1',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {0, +1}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_1_2/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_1_2/README.md',
                                'title': 'UH_1_Subdiag_0_1_2',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {0, +1, +2}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_0_1/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_0_1/README.md',
                                'title': 'UH_1_Subdiag_0_Diag_0_1',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {0, +1}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_0_1_2/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_0_1_2/README.md',
                                'title': 'UH_1_Subdiag_0_Diag_0_1_2',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {0, +1, +2}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_0/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_0/README.md',
                                'title': 'UH_1_Subdiag_0_Diag_n1_0',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {-1, 0}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_0_1/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_0_1/README.md',
                                'title': 'UH_1_Subdiag_0_Diag_n1_0_1',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {-1, 0, +1}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_1/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_1/README.md',
                                'title': 'UH_1_Subdiag_0_Diag_n1_1',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {-1, +1}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_n1_0/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_n1_0/README.md',
                                'title': 'UH_1_Subdiag_n1_0',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {-1, 0}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_n1_0_1/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_n1_0_1/README.md',
                                'title': 'UH_1_Subdiag_n1_0_1',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {-1, 0, +1}.'})
    property_files_list.append({'property_file': 'UpperHessenberg/UH_1_Subdiag_n1_1/Properties.csv',
                                'readme_file': 'UpperHessenberg/UH_1_Subdiag_n1_1/README.md',
                                'title': 'UH_1_Subdiag_n1_1',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {-1, +1}.'})

    for p_dict in property_files_list:
        print(p_dict['property_file'])
        write_readme(p_dict['title'],
                     p_dict['population_title'],
                     property_file = p_dict['property_file'],
                     readme_file = p_dict['readme_file'])
    
        