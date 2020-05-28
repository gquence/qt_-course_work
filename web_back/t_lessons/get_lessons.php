<?php
include_once '../common.php';

function get_lessons($POST)
{
    if (((isset($POST['id'])) && ($POST['id'] !== ""))){
        $in_id          = $POST['id'];
        ft_check_id($in_id);
        $where = "lesson_id = " . $in_id;
    }
    if ((isset($POST['name'])) && ($POST['name'] !== ""))
    {
        $in_name         = $POST['name'];
        ft_check_subjname($in_name);
        if ($where === "")
        {
            $where = "name = '" . $in_name . "'";
        }
        else
            $where = $where . " and name = '" . $in_name. "'";
    }
    if (!isset($where))
        throw new InvalidJsonValues('Empty JSON');
    if (!ft_db_select_check("t_lessons",  $where)){
        return array('result' => "No lessons with this id");
    }

    return (ft_db_select("*", "t_lessons",  $where));
}

function get_all($POST)
{   
    return (ft_db_select("*", "t_lessons", ""));
}


?>