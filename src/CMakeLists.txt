#SET (ELISE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(SAN_DIR "SAN")
set(AMD_DIR "AMD")
set(HASSA_DIR "HassanArrangt")
set(XINTER_DIR "xinterf")
set(VECTO_DIR "vectorize")
set(UTIL_DIR "util")
set(TIFF_DIR "tiff")
set(SIMULPH_DIR "SimulPhgr")
set(PSC_DIR "post_script")
set(PHOTOGR_DIR "photogram")
set(OPERATOR_DIR "operator")
set(ORIPHO_DIR "ori_phot")
set(OUTPUT_DIR "output")
set(XMLGEN_DIR "XML_GEN")
set(RECIPES_DIR "recipes")
set(RAS_DIR "ras_vect")
set(RADIOM_DIR "radiom")
set(PLOTTER_DIR "plotter")
set(TOP_DIR "top_level")
set(ALOG_SPE_DIR "algo_speciaux")
set(API_DIR "api")
set(BITM_DIR "bitm")
set(COMPRE_DIR "compression")
set(CORREL_DIR "correl")
set(FILE_IMAGE_DIR "file_image")
set(FLUX_PTS_DIR "flux_pts")
set(FONC_NUM_DIR "fonc_num")
set(GEOM2D_DIR "geom2d")
set(GEOM3D_DIR "geom3d")
set(HOUGH_DIR "hough")
set(MEMORY_DIR "memory")
set(MORPHO_DIR "morpho_cabl")
set(MULLGES_DIR "mullgesuhlig")
set(NEIGH_DIR "neighboor")
set(OP_BUF_DIR "op_buf")
set(OPTIM_DIR "optim")
set(UTI_FILES_DIR "uti_files")
set(SAMPLESLIBELISE_DIR "SamplesLibElise")
set(UTI_IMAGE_DIR "uti_image")
set(UTI_PHGRM_DIR "uti_phgrm")
set(UTI_ETAPOLY_DIR "EtalonnagePolygone")
set(POISSON_DIR "poisson")

INCLUDE (${AMD_DIR}/Sources.cmake)
INCLUDE (${HASSA_DIR}/Sources.cmake)
INCLUDE (${SAN_DIR}/Sources.cmake)
INCLUDE (${SIMULPH_DIR}/Sources.cmake)
INCLUDE (${XMLGEN_DIR}/Sources.cmake)
INCLUDE (${ALOG_SPE_DIR}/Sources.cmake)
INCLUDE (${API_DIR}/Sources.cmake)
INCLUDE (${BITM_DIR}/Sources.cmake)
INCLUDE (${COMPRE_DIR}/Sources.cmake)
INCLUDE (${CORREL_DIR}/Sources.cmake)
INCLUDE (${FILE_IMAGE_DIR}/Sources.cmake)
INCLUDE (${FLUX_PTS_DIR}/Sources.cmake)
INCLUDE (${FONC_NUM_DIR}/Sources.cmake)
INCLUDE (${GEOM2D_DIR}/Sources.cmake)
INCLUDE (${GEOM3D_DIR}/Sources.cmake)
INCLUDE (${HOUGH_DIR}/Sources.cmake)
INCLUDE (${MEMORY_DIR}/Sources.cmake)
INCLUDE (${MORPHO_DIR}/Sources.cmake)
#INCLUDE (${MULLGES_DIR}/Sources.cmake)
INCLUDE (${NEIGH_DIR}/Sources.cmake)
INCLUDE (${OP_BUF_DIR}/Sources.cmake)
INCLUDE (${OPERATOR_DIR}/Sources.cmake)
INCLUDE (${OPTIM_DIR}/Sources.cmake)
INCLUDE (${UTI_FILES_DIR}/Sources.cmake)
INCLUDE (${SAMPLESLIBELISE_DIR}/Sources.cmake)
INCLUDE (${UTI_IMAGE_DIR}/Sources.cmake)
INCLUDE (${UTI_PHGRM_DIR}/Sources.cmake)
INCLUDE (${ORIPHO_DIR}/Sources.cmake)
INCLUDE (${OUTPUT_DIR}/Sources.cmake)
INCLUDE (${PHOTOGR_DIR}/Sources.cmake)
INCLUDE (${PLOTTER_DIR}/Sources.cmake)
INCLUDE (${PSC_DIR}/Sources.cmake)
INCLUDE (${RADIOM_DIR}/Sources.cmake)
INCLUDE (${RAS_DIR}/Sources.cmake)
INCLUDE (${RECIPES_DIR}/Sources.cmake)
INCLUDE (${TIFF_DIR}/Sources.cmake)
INCLUDE (${TOP_DIR}/Sources.cmake)
INCLUDE (${UTIL_DIR}/Sources.cmake)
INCLUDE (${VECTO_DIR}/Sources.cmake)
INCLUDE (${XINTER_DIR}/Sources.cmake)
INCLUDE (${POISSON_DIR}/Sources.cmake)

if(${WITH_ETALONPOLY})
	INCLUDE (${UTI_ETAPOLY_DIR}/Sources.cmake)
	set( LIB_ETAL_POLYG libEtalPolyg )
endif()

# ORGANISATION des en-tetes ELISE et fichiers Xml
file(GLOB_RECURSE IncFiles ${PROJECT_SOURCE_DIR}/include/*.h  )
file(GLOB_RECURSE XmlFiles ${PROJECT_SOURCE_DIR}/include/*.xml  )

list(APPEND IncFiles ${XmlFiles})

# Construction de l'arborescence des fichiers INCLUDE
foreach(source_file ${IncFiles})
	get_filename_component(VarName ${source_file}  ABSOLUTE)
	get_filename_component(NameFile ${source_file}  NAME)

	string(REGEX REPLACE "/${NameFile}" "" includeTree ${VarName})
	string(REGEX REPLACE "${PROJECT_SOURCE_DIR}/" "" includeTree ${includeTree})
	string(REGEX REPLACE "/" "\\\\\\\\" includeTree ${includeTree})
	source_group("${includeTree}" FILES ${source_file})
endforeach(source_file)

if(${CUDA_ENABLED})
	 file(GLOB_RECURSE IncFilesGpGpu ${PROJECT_SOURCE_DIR}/include/GpGpu/*.h  )
	 list(REMOVE_ITEM IncFiles ${IncFilesGpGpu})
endif()

# OPTION BUILD : En tetes precompilées visual studio

enable_precompiled_headers_msvc(StdAfx.h Elise_Src_Files)

# fichiers qui n'utilisent pas les en tetes precompilées
set(Elise_Src_Files
	${Elise_Src_Files}
	${UTIL_DIR}/win_regex.c
	${TIFF_DIR}/el_dcraw.c
	${OPTIM_DIR}/opt_mat_creuse.cpp
	${OPTIM_DIR}/opt_sysl2.cpp
	${MULLGES_DIR}/mubasic.cpp
	${MULLGES_DIR}/muflaguer.cpp
	${MULLGES_DIR}/mufmueller.cpp
	${MULLGES_DIR}/muvmblock.cpp
	${ORIPHO_DIR}/cOriMntCarto.cpp
)

set(libElise elise)

# CONSTRUCTION : Lib ELISE
if(${CUDA_ENABLED})

	 file(GLOB_RECURSE IncuhCudaFiles ${PROJECT_SOURCE_DIR}/include/*.cuh  )
	 file(GLOB_RECURSE IncCudaFiles ${PROJECT_SOURCE_DIR}/include/*.h  )
	 list(APPEND IncCudaFiles ${IncuhCudaFiles})

	 #set(GENCODE_SM20 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20 -lineinfo)
	 #set(GENCODE_SM20 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20 -use_fast_math)
	 #set(GENCODE_SM21 -gencode=arch=compute_21,code=sm_21 -gencode=arch=compute_21,code=compute_21)

	 #set(GENCODE_SM20 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20)

	 set(GENCODE_SM20 -gencode=arch=compute_20,code=sm_20)
	 set(libStatGpGpuTools GpGpuTools)
	 set(libStatGpGpuInterfMicMac GpGpuInterfMicMac)
	 set(libStatGpGpuOpt GpGpuOpt)
	 set(TestExeGpGpuOpt TestGpGpuOpt)

	 cuda_add_library(${libStatGpGpuTools}  ${GpGpuTools_Src_Files} STATIC OPTIONS ${GENCODE_SM20})

	 cuda_add_library(${libStatGpGpuInterfMicMac}  ${uti_phgrm_GpGpu_Src_Files} STATIC OPTIONS ${GENCODE_SM20})

	 cuda_add_library(${libStatGpGpuOpt}  ${uti_phgrm_Opt_GpGpu_Src_Files} ${IncCudaFiles} STATIC OPTIONS ${GENCODE_SM20})

	 if (Boost_FOUND)
		  target_link_libraries(${libStatGpGpuInterfMicMac}  ${Boost_LIBRARIES} ${Boost_THREADAPI})
		  if (NOT WIN32)
			target_link_libraries(${libStatGpGpuInterfMicMac}  rt pthread )
		  endif()
	 endif()

	 cuda_add_executable(${TestExeGpGpuOpt} ${uti_Test_Opt_GpGpu_Src_Files})

	 target_link_libraries(${TestExeGpGpuOpt}  ${Boost_LIBRARIES} ${Boost_THREADAPI} ${libStatGpGpuOpt} rt pthread ${libStatGpGpuTools})

	 link_directories(${PROJECT_SOURCE_DIR}/lib/)

	 cuda_add_library( ${libElise} ${Elise_Src_Files} ${IncFiles} OPTIONS ${GENCODE_SM20})

	 target_link_libraries(${libElise}  ${libStatGpGpuTools} ${libStatGpGpuInterfMicMac} ${libStatGpGpuOpt})

	 INSTALL(TARGETS ${TestExeGpGpuOpt} RUNTIME DESTINATION ${Install_Dir})

	 INSTALL(TARGETS ${libStatGpGpuTools} ${libStatGpGpuInterfMicMac} ${libStatGpGpuOpt}
		    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
		    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib)

else()
	 add_library( elise ${Elise_Src_Files} ${IncFiles} )
	 INSTALL(TARGETS elise ARCHIVE DESTINATION ${Install_Dir_lib} )
endif()

# OPTION BUILD : En tetes precompilees pour gcc
enable_precompiled_headers_GCC(StdAfx.h ${libElise})

# DEFINITION
add_definitions(-DNO_JPEG -DNO_LCMS)

# INSTALLATION : Dossier de destination lors de l'install
#install(TARGETS elise ARCHIVE DESTINATION ${Install_Dir})

ADD_SUBDIRECTORY(CBinaires)

if (WITH_INTERFACE)
    ADD_SUBDIRECTORY(interface)
endif()
