#!/usr/local/bin/perl

# usage: perl bigrun.pl 

$wrkdir = "/star/u/jjiastar/pwg/Spin/production";

#system("mkdir tmpAMPT");
#system("mkdir tmpAMPT/log");

# open file as read_only
$runlistfile ="Run24pp_run.lst";
open(RUNLIST,"< $runlistfile") or die "Can not open ${runfilelist} !\n";
@runlist=<RUNLIST>;

@tail=("00","01","02","03","04","05","06","07","08","09","10","11","12");

#149

for($i=117; $i<287; $i++) {

    $run =$runlist[$i];

    print $i; print "\n";

    print $run; print "\n";

    chomp($run);

    system("mkdir $run");
    
    chdir("$run");
    $filelistfile = "$wrkdir/lst/$run.list";
    print $filelistfile; print "\n";

    $nfile = `wc -l < $filelistfile`;
    die "wc failed: $?" if $?;
    chomp($nfile);
    print $nfile; print "\n";
 
    `split $filelistfile $run. -l 50 -d`;
    $nlst = int($nfile/50)+1; 

    for($j=0; $j<$nlst; $j++){
	print $tail[$j]; print "\n";
        $splitfile="$run.$tail[$j]";
	$splitfile2="$run.$tail[$j].list";
	print $splitfile; print "\n"; 
	`mv $splitfile $splitfile2`;
	#creates a standard condor file
    
	my @arguments = ($i, $j);
	$CondorJob="FlyCondor_$j";
	open(FO,"> $CondorJob");

	print FO "Universe        = vanilla\n";
	print FO "Notification    = Error\n"; # only notify conductor if job terminates abnormally!
	print FO "Executable      = $wrkdir/runsegRun24pp.pl\n";
	print FO "Arguments       = @arguments\n";
	print FO "Requirements    = CPU_Speed >= 1\n";
	print FO "Rank            = CPU_Speed\n";
	print FO "Priority        = +20\n";
	print FO "GetEnv          = True\n";
	print FO "Input           = /dev/null\n";
	print FO "Output          = $wrkdir/logs/$run.$j.out\n";
	print FO "Error           = $wrkdir/logs/$run.$j.err\n";
	print FO "Log             = $wrkdir/logs/$run.$j.log\n";
#    print FO "Notify_user     = shengli.huang\@vanderbilt.edu\n";
	print FO "+Experiment     = \"star\"\n";
	print FO "+Job_Type       = \"cas\"\n";
	print FO "Queue\n";
        
	close(FO); 

	chdir("..");

        system("condor_submit $run/$CondorJob");
	
	chdir("$run");
    }

    chdir("..");
# to sleep in seconds		
   sleep 1;

    
}  # end of while file_list

# to close the file handles
close RUNLIST;

