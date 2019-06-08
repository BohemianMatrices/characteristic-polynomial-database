import os
import glob

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


def get_properties_subsection(properties_dict, header_name, subproperties, n_min, n_max):
    
    s = ''
    
    # Header
    s += '### {}\n\n'.format(header_name)

    # Table header
    s += '| Matrix Size |'
    for ss in subproperties:
        s += ' {} |'.format(ss)
    s += '\n'

    # Table separator
    s += '| --- |'
    for _ in subproperties:
        s += ' --- |'
    s += '\n'

    # OEIS line
    s += '| [__OEIS__](https://oeis.org/) |'
    for ss in subproperties:
        if properties_dict[ss]['oeis'] != '':
            s += ' [__{0}__](https://oeis.org/{0})'.format(properties_dict[ss]['oeis'])
        s += ' |'
    s += '\n'

    # Property values
    for i in range(n_min, n_max+1):
        s += '| {0}x{0} |'.format(i)

        for ss in subproperties:
            if properties_dict[ss][str(i)] == '':
                s += ' |'
            else:
                s += ' {:,} |'.format(int(properties_dict[ss][str(i)]))
        s += '\n'
    s += '\n'
    
    return s


def get_properties_section(data_dir,
                           property_file = 'Properties.csv'):
    
    # Load properties from file
    (properties_dict, n_min, n_max) = get_properties(property_file = property_file)
    
    s = ''
    
    # Properties header
    s += '## Properties\n\n'
    
    s += 'Download all properties: <a href=\"http://cpdb.bohemianmatrices.com/{}/Properties.csv\">Properties.csv</a>\n\n'.format(data_dir[:-5])
    
    # ------------------------------------------------------------------------ #
    # Characteristic Polynomials                                               #
    # ------------------------------------------------------------------------ #
    header_name = 'Characteristic Polynomials'
    subproperties = ['Number of Matrices',
                     'Number of Characteristic Polynomials',
                     'Number of Minimal Polynomials',
                     'Number of Non-Derogatory Matrices',
                     'Maximum Characteristic Height']
    s += get_properties_subsection(properties_dict, header_name, subproperties, n_min, n_max)
    
    # ------------------------------------------------------------------------ #
    # Eigenvalues                                                              #
    # ------------------------------------------------------------------------ #
    header_name = 'Eigenvalues'
    subproperties = ['Number of Distinct Eigenvalues',
                     'Number of Distinct Real Eigenvalues',
                     'Number of Distinct Purely Complex Eigenvalues',
                     'Number of Distinct Jordan Canonical Forms']
    s += get_properties_subsection(properties_dict, header_name, subproperties, n_min, n_max)
    
    # ------------------------------------------------------------------------ #
    # Rank                                                                     #
    # ------------------------------------------------------------------------ #
    header_name = 'Rank'
    subproperties = ['Number of Singular Matrices',
                     'Number of Non-Singular Matrices']
    for i in range(1, n_max+1):
        subproperties.append('Number of Rank {} Matrices'.format(i))
    s += get_properties_subsection(properties_dict, header_name, subproperties, n_min, n_max)
    
    # ------------------------------------------------------------------------ #
    # Determinant                                                              #
    # ------------------------------------------------------------------------ #
    header_name = 'Determinant'
    subproperties = ['Number of Distinct Determinants',
                     'Maximum Determinant',
                     'Number of Unimodular Matrices']
    s += get_properties_subsection(properties_dict, header_name, subproperties, n_min, n_max)
    
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
    s += get_properties_subsection(properties_dict, header_name, subproperties, n_min, n_max)
    
    return s


def sizeof_fmt(num, suffix='B'):
    for unit in ['','K','M','G','T','P','E','Z']:
        if abs(num) < 1024.0:
            return "%.0f%s%s" % (num, unit, suffix)
        num /= 1024.0
    return "%.0f%s%s" % (num, 'Y', suffix)


def get_data_section(data_dir, title):
    
    s = ''
    
    # Characteristic polynomials
    s += '## Characteristic Polynomials\n\n'
    
    s += 'Download all characteristic polynomials:\n'
    
    # CharPolys.zip
    fsize = sizeof_fmt(os.path.getsize('{}/CharPolys.zip'.format(data_dir)))
    s += '- <a href=\"http://cpdb.bohemianmatrices.com/{}/CharPolys.zip\">CharPolys.zip</a> ({})\n'.format(data_dir, fsize)
    
    # CharPolys.tar.gz
    fsize = sizeof_fmt(os.path.getsize('{}/CharPolys.tar.gz'.format(data_dir)))
    s += '- <a href=\"http://cpdb.bohemianmatrices.com/{}/CharPolys.tar.gz\">CharPolys.tar.gz</a> ({})\n\n'.format(data_dir, fsize)
    
    # Char poly table
    s += '| Matrix Size | .csv | .zip | .tar.gz |\n'
    s += '| --- | --- | --- | --- |\n'
    csv_fnames = list(glob.iglob('{}/CharPolys_*.csv'.format(data_dir), recursive=True))
    n_min = min([int(c[-5]) for c in csv_fnames])
    n_max = max([int(c[-5]) for c in csv_fnames])
    for i in range(n_min, n_max+1):
        s += '| {}x{} '.format(i, i)
        fsize = sizeof_fmt(os.path.getsize('{}/CharPolys_{}x{}.csv'.format(data_dir, i, i)))
        s += '| <a href="http://cpdb.bohemianmatrices.com/{}/CharPolys_{}x{}.csv">CharPolys_{}x{}.csv</a> ({})'.format(data_dir, i, i, i, i, fsize)
        fsize = sizeof_fmt(os.path.getsize('{}/CharPolys_{}x{}.zip'.format(data_dir, i, i)))
        s += '| <a href="http://cpdb.bohemianmatrices.com/{}/CharPolys_{}x{}.zip">CharPolys_{}x{}.zip</a> ({})'.format(data_dir, i, i, i, i, fsize)
        fsize = sizeof_fmt(os.path.getsize('{}/CharPolys_{}x{}.tar.gz'.format(data_dir, i, i)))
        s += '| <a href="http://cpdb.bohemianmatrices.com/{}/CharPolys_{}x{}.tar.gz">CharPolys_{}x{}.tar.gz</a> ({}) |\n'.format(data_dir, i, i, i, i, fsize)
        
    s += '\n'
    
    # Minimal polynomials
    s += '## Minimal Polynomials\n\n'
    
    s += 'Download all minimal polynomials:\n'
    
    # MinPolys.zip
    fsize = sizeof_fmt(os.path.getsize('{}/MinPolys.zip'.format(data_dir)))
    s += '- <a href=\"http://cpdb.bohemianmatrices.com/{}/MinPolys.zip\">MinPolys.zip</a> ({})\n'.format(data_dir, fsize)
    
    # MinPolys.tar.gz
    fsize = sizeof_fmt(os.path.getsize('{}/MinPolys.tar.gz'.format(data_dir)))
    s += '- <a href=\"http://cpdb.bohemianmatrices.com/{}/MinPolys.tar.gz\">MinPolys.tar.gz</a> ({})\n\n'.format(data_dir, fsize)
    
    # Min poly table
    s += '| Matrix Size | .csv | .zip | .tar.gz |\n'
    s += '| --- | --- | --- | --- |\n'
    csv_fnames = list(glob.iglob('{}/MinPolys_*.csv'.format(data_dir), recursive=True))
    n_min = min([int(c[-5]) for c in csv_fnames])
    n_max = max([int(c[-5]) for c in csv_fnames])
    for i in range(n_min, n_max+1):
        s += '| {}x{} '.format(i, i)
        fsize = sizeof_fmt(os.path.getsize('{}/MinPolys_{}x{}.csv'.format(data_dir, i, i)))
        s += '| <a href="http://cpdb.bohemianmatrices.com/{}/MinPolys_{}x{}.csv">MinPolys_{}x{}.csv</a> ({})'.format(data_dir, i, i, i, i, fsize)
        fsize = sizeof_fmt(os.path.getsize('{}/MinPolys_{}x{}.zip'.format(data_dir, i, i)))
        s += '| <a href="http://cpdb.bohemianmatrices.com/{}/MinPolys_{}x{}.zip">MinPolys_{}x{}.zip</a> ({})'.format(data_dir, i, i, i, i, fsize)
        fsize = sizeof_fmt(os.path.getsize('{}/MinPolys_{}x{}.tar.gz'.format(data_dir, i, i)))
        s += '| <a href="http://cpdb.bohemianmatrices.com/{}/MinPolys_{}x{}.tar.gz">MinPolys_{}x{}.tar.gz</a> ({}) |\n'.format(data_dir, i, i, i, i, fsize)
        
    s += '\n'
    
    return s

def write_readme(data_dir,
                 population_title):
    
    class_name = data_dir.split('/')[1]
    subclass_name = data_dir.split('/')[0]
    permalink = '/cpdb/{}'.format(data_dir[:-5].lower())
    property_file = '{}/Properties.csv'.format(data_dir[:-5])
    output_file = '../BohemianMatrices/cpdb/{}.md'.format(data_dir[:-5].lower())
    
    # yaml header
    s = '---\n'
    s += 'layout: page\n'
    s += 'title: {}\n'.format(class_name)
    s += 'permalink: {}\n'.format(permalink)
    s += '---\n\n'
    
    s += '{% include nav-breadcrumbs.html %}\n\n'
    
    s += '{}\n\n'.format(population_title)
    
    # Data section
    s += get_data_section(data_dir, class_name)
    s += '\n\n'
    
    # Get the properties section
    s += get_properties_section(data_dir,
                                property_file = property_file)
    
    with open(output_file, 'w') as f:
        f.write(s)

if __name__ == '__main__':
    
    import glob
    import os
    
    property_files_list = []
    
    # Unstructured
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_1/Data',
                                'population_title': 'Matrices with entries from the set {0, +1}.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_1_2/Data',
                                'population_title': 'Matrices with entries from the set {0, +1, +2}.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_Diag_0_1/Data',
                                'population_title': 'Matrices with entries from the set {0, +1} and diagonal entries fixed at 0.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_Diag_0_1_2/Data',
                                'population_title': 'Matrices with entries from the set {0, +1, +2} and diagonal entries fixed at 0.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_Diag_n1_0/Data',
                                'population_title': 'Matrices with entries from the set {-1, 0} and diagonal entries fixed at 0.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_Diag_n1_0_1/Data',
                                'population_title': 'Matrices with entries from the set {-1, 0, +1} and diagonal entries fixed at 0.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_0_Diag_n1_1/Data',
                                'population_title': 'Matrices with entries from the set {-1, +1} and diagonal entries fixed at 0.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_n1_0/Data',
                                'population_title': 'Matrices with entries from the set {-1, 0}.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_n1_0_1/Data',
                                'population_title': 'Matrices with entries from the set {-1, 0, +1}.'})
    property_files_list.append({'data_dir': 'Unstructured/Unstructured_n1_1/Data',
                                'population_title': 'Matrices with entries from the set {-1, +1}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_1/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {0, +1}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_1_2/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {0, +1, +2}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_Diag_0_1/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {0, +1}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_Diag_0_1_2/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {0, +1, +2}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_0/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {-1, 0}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_0_1/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {-1, 0, +1}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_0_Diag_n1_1/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1, diagonal entries fixed at 0, and all other entries from the set {-1, +1}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_n1_0/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {-1, 0}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_n1_0_1/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {-1, 0, +1}.'})
    property_files_list.append({'data_dir': 'UpperHessenberg/UH_1_Subdiag_n1_1/Data',
                                'population_title': 'Upper Hessenberg matrices with subdiagonal entries fixed at 1 and all other entries from the set {-1, +1}.'})
    
    for p_dict in property_files_list:
        print(p_dict['data_dir'])
        write_readme(p_dict['data_dir'],
                     p_dict['population_title'])
    
    
    