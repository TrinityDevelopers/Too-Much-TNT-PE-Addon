                                                              
 PathEd - PathEditor win32 command-line utility (ver. 1.0)      
                                                        
 Copyright (C) 2007 by Predrag Cordas (Under Gnu Lesser General Public License)

 This program is free software; you can redistribute it and/or modify
 it under the terms of the Gnu Lesser General Public License
 (Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>).

 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

 Project URL: http://sourceforge.net/projects/pathed/                                                           
                                                                                     
 Usage: PathEd [option] [text]                                                     
                                                                                     
 Options:          -h, --help          			 This help                                       
                   -s  SearchString              Search for string inside PATH registry key (case sensitive)   
                   -S  SearchString              Search for string inside PATH registry key (not case sensitive)   
                   -p                            Print PATH registry key value   
                   -P                            Print PATH registry key value with \n instead of ; character   
                   -a  AppendString              Append path entry at the end of PATH registry key    
                   -d  DeleteString              Delete string from the PATH registry key    
                   -r  ReplaceString NewString   Replace path entry string with new one in the PATH registry key    
 
                   -q                            quiet mode - only output is %ERRORLEVEL% !!    
 
 Exit status (%ERRORLEVEL% variable) is 0 if done OK, 1 if error. 
 
 Some usage examples:    

   search to see if c:\php4 exists in system PATH in registry:  pathed -S c:\php4 

   append c:\php5 in system PATH:                               pathed -a c:\php5 

   delete c:\php4 from system PATH (without verbous output):    pathed -dq c:\php4  

   replace c:\php4 with c:\php5 (quietly):                      pathed -rq c:\php4 c:\php5 
 


 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 
 
