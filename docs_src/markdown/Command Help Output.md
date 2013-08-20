Drush Rush Commands Help Text {#doc-commands-help}
=============================

@brief  A guide to help you find what you need to use Drush Rush.

Help Documentation Output for Drush Rush Commands {#page-commands-help}
=================================================

[TOC]

## rush Help Text {#sec-commands-help-rush}

     Run rush operations defined in Rush job files.

     Drush rush is a tool to enhance and improve Drupal development operations and work flow.

     Examples:
      drush rush jobName                        Run the rush files within the job directory named "jobName"
      drush rush jobName.subJob                 Run the rush files within the job directory named "jobName/subJob"
      drush rush jobName --show=ops             Parse rush files and output the rush operations that would occur if the rush file were run.
      drush rush jobName --show=params          Parse rush param files and output all params (rush jobName plus global directory) for inspection.
      drush rush jobName --rush=clean           Run the rush job within the "jobName" and use the rush file `clean.rush.ini` or `clean.rush.php`


     Arguments:
      job                                       Required. The name of the job directory within the Rush Application folder.


     Options:
      --domain=<mydomain.local>                 Domain to use for jobs that use the [build][domain] parameter.

                                                Example: --domain=mydomain.dev


      --rush=<un,pre-build,post-build>          Rush prefix to select a different rush.ini or rush.php to run.

                                                Example: --rush=un  [Build the job using rush files named `un.rush.ini` or `un.rush.php`.
                                                `un.rush.ini` could be a tear down rush file.]


      --show=<ops,params,paths,si,derived,desc  Show mode. Utility to inspect operations or params without actually
      ,help,h>                                  running the job.

                                                  Examples:

                                                  --show=params  [Show all parameters the job may use.]
                                                  --show=ops     [Show all ops the job will run.]
                                                  --show=paths   [Show all paths the job may use.]
                                                  --show=si      [Show the parameters which the si operation would use if run.]
                                                  --show=derived [Show the parameters which rush derived for the job.]
                                                  --show=desc    [Show the build description.]
                                                  --show=help    [Show the job description and help text.]
                                                  --show=h       [Alias for --show=help]


     Aliases: dr

## rush-list Help Text {#sec-commands-help-rush-list}

    List all the jobs in the Rush Application folder jobs directory.

    Examples:
     drush rush-list                           List all the jobs in the job directory.
     drush rush-list --show=jt                 List all the jobs in the job templates directory.


    Options:
     --show=<job-templates,jt>                 Show mode. Utility to inspect operations or params without actually
                                               running the job.

                                                 Examples:

                                                 --show=job-templates  [show jobs in the job templates directory instead of the jobs directory]
                                                 --show=jt             [alias for --show=job-templates]




    Aliases: drl

## rush-show Help Text {#sec-commands-help-rush-show}

    A utility to inspect operations or params without actually running a job.
    This is a convenience command which does the same thing as running rush with the --show option.

    Examples:
     drush rush-show jobName ops               Show all ops the job will run.
     drush rush-show jobName params            Show all parameters the job may use.


    Arguments:
     job                                       Required. The name of the job directory within the Rush Application folder.
     show_mode                                 Required. The name of the job directory within the Rush Application folder.


    Options:
     --domain=<mydomain.local>                 Domain to use for jobs that use the [build][domain] parameter.

                                               Example: --domain=mydomain.dev


     --rush=<un,pre-build,post-build>          Rush prefix to select a different rush.ini or rush.php to run.

                                               Example: --rush=un  [Build the job using rush files named `un.rush.ini` or `un.rush.php`.
                                               `un.rush.ini` could be a tear down rush file.]




    Aliases: drs